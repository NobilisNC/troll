cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(troll VERSION 1.0.0 LANGUAGES CXX)


# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

##	 Qt5	##
find_package(Qt5Widgets REQUIRED)


##      Ressources files        ##
qt5_add_resources(
  QRCS
  resources/resources.qrc
  )

##      UIs     ##
qt5_wrap_ui(
  UI_HEADERS
  mainwindow.ui
  )


##      Executable       ##
add_executable(
  troll
  WIN32

  main.cc
  mainwindow.cc
  ${QRCS}
   ${UI_HEADERS}
  )

target_link_libraries(
  troll
  PUBLIC
  Qt5::Widgets
  )
	
##      Compiler Options        ##
target_compile_features(
  troll
  PUBLIC
  cxx_std_17
  )



##	 Include	 ##
target_include_directories(
  troll
  PRIVATE
  .

  )







