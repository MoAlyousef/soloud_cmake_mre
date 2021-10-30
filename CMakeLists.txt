cmake_minimum_required(VERSION 3.0)
project(soloud_repro)

find_package(Threads REQUIRED)

include(FetchContent)
FetchContent_Declare(SOLOUD
    GIT_REPOSITORY https://github.com/jarikomppa/soloud
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(SOLOUD)

add_compile_definitions(WITH_MINIAUDIO)
set(BACKEND_SRCS ${soloud_SOURCE_DIR}/src/backend/miniaudio/soloud_miniaudio.cpp)
file(GLOB_RECURSE AUDIOSOURCE ${soloud_SOURCE_DIR}/src/audiosource/*.c*)
file(GLOB_RECURSE CORE ${soloud_SOURCE_DIR}/src/core/*.c*)
file(GLOB_RECURSE FILTER ${soloud_SOURCE_DIR}/soloud/src/filter/*.c*)

set(SOLOUD_SRCS 
    ${BACKEND_SRCS}
    ${AUDIOSOURCE}
    ${CORE}
    ${FILTER}
)

add_executable(app src/main.cpp ${SOLOUD_SRCS})
target_include_directories(app PUBLIC ${soloud_SOURCE_DIR}/include)
target_link_libraries(app PRIVATE ${CMAKE_DL_LIBS} Threads::Threads)
