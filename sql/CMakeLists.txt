add_subdirectory(trinityzero_updates)
add_subdirectory(tools)


########### install files ###############

FILE(GLOB _SQL *.sql)

install(FILES ${_SQL} DESTINATION share/trinity/sql/updates)
