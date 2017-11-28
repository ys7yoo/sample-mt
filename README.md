# sample-mt
sampling with multi threads on RPI

# How to use?
## 1. Install boost

```bash
sudo apt install libboost1.62-all-dev
```

Then, you will see lots of libraries installed under /usr/lib/arm-linux-gnueabihf/.

```bash
$ls /usr/lib/arm-linux-gnueabihf/libboost*
/usr/lib/arm-linux-gnueabihf/libboost_atomic.a
/usr/lib/arm-linux-gnueabihf/libboost_atomic.so
/usr/lib/arm-linux-gnueabihf/libboost_atomic.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_chrono.a
/usr/lib/arm-linux-gnueabihf/libboost_chrono.so
/usr/lib/arm-linux-gnueabihf/libboost_chrono.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_context.a
/usr/lib/arm-linux-gnueabihf/libboost_context.so
/usr/lib/arm-linux-gnueabihf/libboost_context.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_coroutine.a
/usr/lib/arm-linux-gnueabihf/libboost_coroutine.so
/usr/lib/arm-linux-gnueabihf/libboost_coroutine.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_date_time.a
/usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/usr/lib/arm-linux-gnueabihf/libboost_date_time.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_exception.a
/usr/lib/arm-linux-gnueabihf/libboost_fiber.a
/usr/lib/arm-linux-gnueabihf/libboost_fiber.so
/usr/lib/arm-linux-gnueabihf/libboost_fiber.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_filesystem.a
/usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/usr/lib/arm-linux-gnueabihf/libboost_filesystem.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_graph.a
/usr/lib/arm-linux-gnueabihf/libboost_graph_parallel.a
/usr/lib/arm-linux-gnueabihf/libboost_graph_parallel.so
/usr/lib/arm-linux-gnueabihf/libboost_graph_parallel.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_graph.so
/usr/lib/arm-linux-gnueabihf/libboost_graph.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_iostreams.a
/usr/lib/arm-linux-gnueabihf/libboost_iostreams.so
/usr/lib/arm-linux-gnueabihf/libboost_iostreams.so.1.58.0
/usr/lib/arm-linux-gnueabihf/libboost_iostreams.so.1.60.0
/usr/lib/arm-linux-gnueabihf/libboost_iostreams.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_locale.a
/usr/lib/arm-linux-gnueabihf/libboost_locale.so
/usr/lib/arm-linux-gnueabihf/libboost_locale.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_log.a
/usr/lib/arm-linux-gnueabihf/libboost_log_setup.a
/usr/lib/arm-linux-gnueabihf/libboost_log_setup.so
/usr/lib/arm-linux-gnueabihf/libboost_log_setup.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_log.so
/usr/lib/arm-linux-gnueabihf/libboost_log.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_math_c99.a
/usr/lib/arm-linux-gnueabihf/libboost_math_c99f.a
/usr/lib/arm-linux-gnueabihf/libboost_math_c99f.so
/usr/lib/arm-linux-gnueabihf/libboost_math_c99f.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_math_c99.so
/usr/lib/arm-linux-gnueabihf/libboost_math_c99.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_math_tr1.a
/usr/lib/arm-linux-gnueabihf/libboost_math_tr1f.a
/usr/lib/arm-linux-gnueabihf/libboost_math_tr1f.so
/usr/lib/arm-linux-gnueabihf/libboost_math_tr1f.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_math_tr1.so
/usr/lib/arm-linux-gnueabihf/libboost_math_tr1.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_mpi.a
/usr/lib/arm-linux-gnueabihf/libboost_mpi_python.a
/usr/lib/arm-linux-gnueabihf/libboost_mpi_python-py27.a
/usr/lib/arm-linux-gnueabihf/libboost_mpi_python-py27.so
/usr/lib/arm-linux-gnueabihf/libboost_mpi_python-py27.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_mpi_python-py35.a
/usr/lib/arm-linux-gnueabihf/libboost_mpi_python-py35.so
/usr/lib/arm-linux-gnueabihf/libboost_mpi_python-py35.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_mpi_python.so
/usr/lib/arm-linux-gnueabihf/libboost_mpi.so
/usr/lib/arm-linux-gnueabihf/libboost_mpi.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_prg_exec_monitor.a
/usr/lib/arm-linux-gnueabihf/libboost_prg_exec_monitor.so
/usr/lib/arm-linux-gnueabihf/libboost_prg_exec_monitor.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_program_options.a
/usr/lib/arm-linux-gnueabihf/libboost_program_options.so
/usr/lib/arm-linux-gnueabihf/libboost_program_options.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_python.a
/usr/lib/arm-linux-gnueabihf/libboost_python-py27.a
/usr/lib/arm-linux-gnueabihf/libboost_python-py27.so
/usr/lib/arm-linux-gnueabihf/libboost_python-py27.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_python-py35.a
/usr/lib/arm-linux-gnueabihf/libboost_python-py35.so
/usr/lib/arm-linux-gnueabihf/libboost_python-py35.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_python.so
/usr/lib/arm-linux-gnueabihf/libboost_random.a
/usr/lib/arm-linux-gnueabihf/libboost_random.so
/usr/lib/arm-linux-gnueabihf/libboost_random.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_regex.a
/usr/lib/arm-linux-gnueabihf/libboost_regex.so
/usr/lib/arm-linux-gnueabihf/libboost_regex.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_serialization.a
/usr/lib/arm-linux-gnueabihf/libboost_serialization.so
/usr/lib/arm-linux-gnueabihf/libboost_serialization.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_signals.a
/usr/lib/arm-linux-gnueabihf/libboost_signals.so
/usr/lib/arm-linux-gnueabihf/libboost_signals.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_system.a
/usr/lib/arm-linux-gnueabihf/libboost_system.so
/usr/lib/arm-linux-gnueabihf/libboost_system.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_test_exec_monitor.a
/usr/lib/arm-linux-gnueabihf/libboost_thread.a
/usr/lib/arm-linux-gnueabihf/libboost_thread.so
/usr/lib/arm-linux-gnueabihf/libboost_thread.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_timer.a
/usr/lib/arm-linux-gnueabihf/libboost_timer.so
/usr/lib/arm-linux-gnueabihf/libboost_timer.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_type_erasure.a
/usr/lib/arm-linux-gnueabihf/libboost_type_erasure.so
/usr/lib/arm-linux-gnueabihf/libboost_type_erasure.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_unit_test_framework.a
/usr/lib/arm-linux-gnueabihf/libboost_unit_test_framework.so
/usr/lib/arm-linux-gnueabihf/libboost_unit_test_framework.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_wave.a
/usr/lib/arm-linux-gnueabihf/libboost_wave.so
/usr/lib/arm-linux-gnueabihf/libboost_wave.so.1.62.0
/usr/lib/arm-linux-gnueabihf/libboost_wserialization.a
/usr/lib/arm-linux-gnueabihf/libboost_wserialization.so
/usr/lib/arm-linux-gnueabihf/libboost_wserialization.so.1.62.0
```

# 2. Build sample code 
