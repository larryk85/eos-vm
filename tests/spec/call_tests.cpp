#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <catch2/catch.hpp>
#include <utils.hpp>
#include <wasm_config.hpp>
#include <eosio/vm/backend.hpp>

using namespace eosio;
using namespace eosio::vm;
extern wasm_allocator wa;
using backend_t = backend<std::nullptr_t>;

TEST_CASE( "Testing wasm <call_0_wasm>", "[call_0_wasm_tests]" ) {
   auto code = backend_t::read_wasm( call_0_wasm );
   backend_t bkend( code );
   bkend.set_wasm_allocator( &wa );
   bkend.initialize(nullptr);

   CHECK(bkend.call_with_return(nullptr, "env", "type-i32")->to_ui32() == UINT32_C(306));
   CHECK(bkend.call_with_return(nullptr, "env", "type-i64")->to_ui64() == UINT32_C(356));
   CHECK(bit_cast<uint32_t>(bkend.call_with_return(nullptr, "env", "type-f32")->to_f32()) == UINT32_C(1165172736));
   CHECK(bit_cast<uint64_t>(bkend.call_with_return(nullptr, "env", "type-f64")->to_f64()) == UINT64_C(4660882566700597248));
   CHECK(bkend.call_with_return(nullptr, "env", "type-first-i32")->to_ui32() == UINT32_C(32));
   CHECK(bkend.call_with_return(nullptr, "env", "type-first-i64")->to_ui64() == UINT32_C(64));
   CHECK(bit_cast<uint32_t>(bkend.call_with_return(nullptr, "env", "type-first-f32")->to_f32()) == UINT32_C(1068037571));
   CHECK(bit_cast<uint64_t>(bkend.call_with_return(nullptr, "env", "type-first-f64")->to_f64()) == UINT64_C(4610064722561534525));
   CHECK(bkend.call_with_return(nullptr, "env", "type-second-i32")->to_ui32() == UINT32_C(32));
   CHECK(bkend.call_with_return(nullptr, "env", "type-second-i64")->to_ui64() == UINT32_C(64));
   CHECK(bit_cast<uint32_t>(bkend.call_with_return(nullptr, "env", "type-second-f32")->to_f32()) == UINT32_C(1107296256));
   CHECK(bit_cast<uint64_t>(bkend.call_with_return(nullptr, "env", "type-second-f64")->to_f64()) == UINT64_C(4634211053438658150));
   CHECK(bkend.call_with_return(nullptr, "env", "fac", UINT64_C(0))->to_ui64() == UINT32_C(1));
   CHECK(bkend.call_with_return(nullptr, "env", "fac", UINT64_C(1))->to_ui64() == UINT32_C(1));
   CHECK(bkend.call_with_return(nullptr, "env", "fac", UINT64_C(5))->to_ui64() == UINT32_C(120));
   CHECK(bkend.call_with_return(nullptr, "env", "fac", UINT64_C(25))->to_ui64() == UINT32_C(7034535277573963776));
   CHECK(bkend.call_with_return(nullptr, "env", "fac-acc", UINT64_C(0), UINT64_C(1))->to_ui64() == UINT32_C(1));
   CHECK(bkend.call_with_return(nullptr, "env", "fac-acc", UINT64_C(1), UINT64_C(1))->to_ui64() == UINT32_C(1));
   CHECK(bkend.call_with_return(nullptr, "env", "fac-acc", UINT64_C(5), UINT64_C(1))->to_ui64() == UINT32_C(120));
   CHECK(bkend.call_with_return(nullptr, "env", "fac-acc", UINT64_C(25), UINT64_C(1))->to_ui64() == UINT32_C(7034535277573963776));
   CHECK(bkend.call_with_return(nullptr, "env", "fib", UINT64_C(0))->to_ui64() == UINT32_C(1));
   CHECK(bkend.call_with_return(nullptr, "env", "fib", UINT64_C(1))->to_ui64() == UINT32_C(1));
   CHECK(bkend.call_with_return(nullptr, "env", "fib", UINT64_C(2))->to_ui64() == UINT32_C(2));
   CHECK(bkend.call_with_return(nullptr, "env", "fib", UINT64_C(5))->to_ui64() == UINT32_C(8));
   CHECK(bkend.call_with_return(nullptr, "env", "fib", UINT64_C(20))->to_ui64() == UINT32_C(10946));
   CHECK(bkend.call_with_return(nullptr, "env", "even", UINT64_C(0))->to_ui32() == UINT32_C(44));
   CHECK(bkend.call_with_return(nullptr, "env", "even", UINT64_C(1))->to_ui32() == UINT32_C(99));
   CHECK(bkend.call_with_return(nullptr, "env", "even", UINT64_C(100))->to_ui32() == UINT32_C(44));
   CHECK(bkend.call_with_return(nullptr, "env", "even", UINT64_C(77))->to_ui32() == UINT32_C(99));
   CHECK(bkend.call_with_return(nullptr, "env", "odd", UINT64_C(0))->to_ui32() == UINT32_C(99));
   CHECK(bkend.call_with_return(nullptr, "env", "odd", UINT64_C(1))->to_ui32() == UINT32_C(44));
   CHECK(bkend.call_with_return(nullptr, "env", "odd", UINT64_C(200))->to_ui32() == UINT32_C(99));
   CHECK(bkend.call_with_return(nullptr, "env", "odd", UINT64_C(77))->to_ui32() == UINT32_C(44));
   CHECK(bkend.call_with_return(nullptr, "env", "as-select-first")->to_ui32() == UINT32_C(306));
   CHECK(bkend.call_with_return(nullptr, "env", "as-select-mid")->to_ui32() == UINT32_C(2));
   CHECK(bkend.call_with_return(nullptr, "env", "as-select-last")->to_ui32() == UINT32_C(2));
   CHECK(bkend.call_with_return(nullptr, "env", "as-if-condition")->to_ui32() == UINT32_C(1));
   CHECK(bkend.call_with_return(nullptr, "env", "as-br_if-first")->to_ui32() == UINT32_C(306));
   CHECK(bkend.call_with_return(nullptr, "env", "as-br_if-last")->to_ui32() == UINT32_C(2));
   CHECK(bkend.call_with_return(nullptr, "env", "as-br_table-first")->to_ui32() == UINT32_C(306));
   CHECK(bkend.call_with_return(nullptr, "env", "as-br_table-last")->to_ui32() == UINT32_C(2));
   CHECK(bkend.call_with_return(nullptr, "env", "as-call_indirect-first")->to_ui32() == UINT32_C(306));
   CHECK(bkend.call_with_return(nullptr, "env", "as-call_indirect-mid")->to_ui32() == UINT32_C(2));
   CHECK_THROWS_AS(bkend(nullptr, "env", "as-call_indirect-last"), std::exception);
   CHECK(!bkend.call_with_return(nullptr, "env", "as-store-first"));
   CHECK(!bkend.call_with_return(nullptr, "env", "as-store-last"));
   CHECK(bkend.call_with_return(nullptr, "env", "as-memory.grow-value")->to_ui32() == UINT32_C(1));
   CHECK(bkend.call_with_return(nullptr, "env", "as-return-value")->to_ui32() == UINT32_C(306));
   CHECK(!bkend.call_with_return(nullptr, "env", "as-drop-operand"));
   CHECK(bkend.call_with_return(nullptr, "env", "as-br-value")->to_ui32() == UINT32_C(306));
   CHECK(bkend.call_with_return(nullptr, "env", "as-local.set-value")->to_ui32() == UINT32_C(306));
   CHECK(bkend.call_with_return(nullptr, "env", "as-local.tee-value")->to_ui32() == UINT32_C(306));
   CHECK(bkend.call_with_return(nullptr, "env", "as-global.set-value")->to_ui32() == UINT32_C(306));
   CHECK(bkend.call_with_return(nullptr, "env", "as-load-operand")->to_ui32() == UINT32_C(1));
   CHECK(bit_cast<uint32_t>(bkend.call_with_return(nullptr, "env", "as-unary-operand")->to_f32()) == UINT32_C(0));
   CHECK(bkend.call_with_return(nullptr, "env", "as-binary-left")->to_ui32() == UINT32_C(11));
   CHECK(bkend.call_with_return(nullptr, "env", "as-binary-right")->to_ui32() == UINT32_C(9));
   CHECK(bkend.call_with_return(nullptr, "env", "as-test-operand")->to_ui32() == UINT32_C(0));
   CHECK(bkend.call_with_return(nullptr, "env", "as-compare-left")->to_ui32() == UINT32_C(1));
   CHECK(bkend.call_with_return(nullptr, "env", "as-compare-right")->to_ui32() == UINT32_C(1));
   CHECK(bkend.call_with_return(nullptr, "env", "as-convert-operand")->to_ui64() == UINT32_C(1));
}

