# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera

# Include any dependencies generated for this target.
include CMakeFiles/simdata.lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simdata.lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simdata.lib.dir/flags.make

CMakeFiles/simdata.lib.dir/src/extApi.c.o: CMakeFiles/simdata.lib.dir/flags.make
CMakeFiles/simdata.lib.dir/src/extApi.c.o: src/extApi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/simdata.lib.dir/src/extApi.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simdata.lib.dir/src/extApi.c.o   -c /home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera/src/extApi.c

CMakeFiles/simdata.lib.dir/src/extApi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simdata.lib.dir/src/extApi.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera/src/extApi.c > CMakeFiles/simdata.lib.dir/src/extApi.c.i

CMakeFiles/simdata.lib.dir/src/extApi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simdata.lib.dir/src/extApi.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera/src/extApi.c -o CMakeFiles/simdata.lib.dir/src/extApi.c.s

CMakeFiles/simdata.lib.dir/src/extApi.c.o.requires:

.PHONY : CMakeFiles/simdata.lib.dir/src/extApi.c.o.requires

CMakeFiles/simdata.lib.dir/src/extApi.c.o.provides: CMakeFiles/simdata.lib.dir/src/extApi.c.o.requires
	$(MAKE) -f CMakeFiles/simdata.lib.dir/build.make CMakeFiles/simdata.lib.dir/src/extApi.c.o.provides.build
.PHONY : CMakeFiles/simdata.lib.dir/src/extApi.c.o.provides

CMakeFiles/simdata.lib.dir/src/extApi.c.o.provides.build: CMakeFiles/simdata.lib.dir/src/extApi.c.o


CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.o: CMakeFiles/simdata.lib.dir/flags.make
CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.o: src/extApiPlatform.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.o   -c /home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera/src/extApiPlatform.c

CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera/src/extApiPlatform.c > CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.i

CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera/src/extApiPlatform.c -o CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.s

CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.o.requires:

.PHONY : CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.o.requires

CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.o.provides: CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.o.requires
	$(MAKE) -f CMakeFiles/simdata.lib.dir/build.make CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.o.provides.build
.PHONY : CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.o.provides

CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.o.provides.build: CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.o


# Object files for target simdata.lib
simdata_lib_OBJECTS = \
"CMakeFiles/simdata.lib.dir/src/extApi.c.o" \
"CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.o"

# External object files for target simdata.lib
simdata_lib_EXTERNAL_OBJECTS =

libsimdata.lib.a: CMakeFiles/simdata.lib.dir/src/extApi.c.o
libsimdata.lib.a: CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.o
libsimdata.lib.a: CMakeFiles/simdata.lib.dir/build.make
libsimdata.lib.a: CMakeFiles/simdata.lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libsimdata.lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/simdata.lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simdata.lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simdata.lib.dir/build: libsimdata.lib.a

.PHONY : CMakeFiles/simdata.lib.dir/build

CMakeFiles/simdata.lib.dir/requires: CMakeFiles/simdata.lib.dir/src/extApi.c.o.requires
CMakeFiles/simdata.lib.dir/requires: CMakeFiles/simdata.lib.dir/src/extApiPlatform.c.o.requires

.PHONY : CMakeFiles/simdata.lib.dir/requires

CMakeFiles/simdata.lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simdata.lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simdata.lib.dir/clean

CMakeFiles/simdata.lib.dir/depend:
	cd /home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera /home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera /home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera /home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera /home/zmc/Downloads/V-REP_PRO_EDU_V3_5_0_Linux/Vrep-camera/CMakeFiles/simdata.lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simdata.lib.dir/depend

