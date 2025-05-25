#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

int main() {
    CU_initialize_registry();
    CU_basic_run_tests();
    CU_cleanup_registry();
}
