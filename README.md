# Cache-Performance-Analysis-in-C
Cache Performance Analysis in C
Project: Large Dataset Student Record Management System
This project compares two implementations of the same student-record workload.
- baseline.c: singly linked list; one malloc() call per student; pointer-based traversal.
- optimized.c: contiguous dynamic array; one allocation for all records; sequential traversal.
The primary optimization is a change in memory organization and allocation strategy. Both versions use a linear search so the comparison focuses on data layout, pointer chasing, and allocation overhead rather than a different search algorithm.
Files
- baseline.c — baseline linked-list implementation.
- optimized.c — contiguous-array implementation.
- benchmark.py — runs each implementation 10 times for four input sizes, checks matching results, and reports median times and speedup.
Compile
Use GCC with warnings enabled and optimization level -O2:
gcc -std=c11 -Wall -Wextra -pedantic -O2 baseline.c -o baseline
gcc -std=c11 -Wall -Wextra -pedantic -O2 optimized.c -o optimized
Run one test
The optional arguments are record_count and query_count. Defaults are 100,000 records and 100 searches.
./baseline 10000 100
./optimized 10000 100
Each program prints a RESULT line containing the input size, number of queries, number found, checksum, and CPU execution time. Matching found and checksum values indicate that both implementations returned the same search results.
Run all benchmarks
python3 benchmark.py
The script tests 1,000, 10,000, 100,000, and 500,000 records; performs 10 runs per implementation at each size; validates the result counts and checksums; and reports median execution times and speedup (baseline median / optimized median).

Run the benchmark on the same computer, with no unusually heavy background workload. Record the actual output in Section 2 of the analysis document. Do not invent or estimate benchmark results.
Assembly analysis
For Section 3, paste the search_student function from each C file into Compiler Explorer, select the same GCC version and -O2 flags, and capture screenshots of both generated assembly panes. The baseline search follows a next pointer; the optimized search indexes consecutive array elements.
Memory management
The baseline frees every list node with free_students(). The optimized implementation frees its single allocation with free(). Both handle allocation failure and release allocated memory before normal exit.
Expected output format
RESULT records=10000 queries=100 found=100 checksum=... elapsed_seconds=...
Exact checksum and elapsed time depend on the input and machine.
