set_xmakever("2.7.4")

set_project("LearnOpenGL")
set_version("0.0.0")

set_allowedplats("windows", "linux", "macosx")
set_allowedarchs("windows|x64", "linux|x64", "macosx|x86_64")

add_rules("mode.debug", "mode.release")
set_languages("cxx20")

if (is_mode("release")) then
    set_optimize("fastest")
end

add_requires("glfw 3.3.8")
add_requires("glm 0.9.9+8")
add_requires("glad v0.1.36")

local outputdir = "$(mode)-$(os)-$(arch)"

rule("cp-resources")
    after_build(function (target)
        os.cp(target:name() .. "/resources", "build/" .. outputdir .. "/" .. target:name() .. "/bin")
    end)

target("LearnOpenGL")
    set_kind("binary")
    add_rules("cp-resources")

    set_targetdir("build/" .. outputdir .. "/LearnOpenGL/bin")
    set_objectdir("build/" .. outputdir .. "/LearnOpenGL/obj")

    add_files("LearnOpenGL/src/**.cpp")
    add_headerfiles("LearnOpenGL/include/**.hpp", "LearnOpenGL/include/**.h")
    add_includedirs("LearnOpenGL/include/", {public = true})

    add_packages("glfw")
    add_packages("glm")
    add_packages("glad")