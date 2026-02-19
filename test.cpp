#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

TEST_CASE ( "Factorials are computed", "[factorial]") // tag
{
  CHECK( Factorial(0) == 1 ); // assertion
  REQUIRE( Factorial(1) == 1 );
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
  REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE("incrementing values in integer vector", "[addN]")
{
	std::vector<int> v{1,2,3,5,6,7,8,10};

	SECTION("checking with +ve n")
  {
		int n=5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == 6 );
		REQUIRE( res[v.size()-1] == 15 );
		REQUIRE(res[random] == v[random]+n);
	}
	SECTION("checking with -ve n")
  {
		int n=-5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == -4 );
		REQUIRE( res[v.size()-1] == 5 );
		REQUIRE(res[random] == v[random]+n);
	}

}

// MY TEST CASES
TEST_CASE( "String are split at separator into vector", "[split]" ) 
{
	CHECK( Split("a,b,c", ",") == std::vector<std::string>{"a", "b", "c"} );
	CHECK( Split("Hello World!", " ") == std::vector<std::string>{"Hello", "World!"} );
	CHECK( Split("one;two;three;four", ";") == std::vector<std::string>{"one", "two", "three", "four"} );
	CHECK( Split("Eggs, Milk, Bread, Cheese", ", ") == std::vector<std::string>{"Eggs", "Milk", "Bread", "Cheese"} );
}

TEST_CASE( "All occurrences of string are removed", "[removeAllSubstrings]" ) 
{
	CHECK( RemoveAllSubstrings("a,b,c", ",b,") == "ac" );
	CHECK( RemoveAllSubstrings("Hello World!", "o") == "Hell Wrld!" );
	CHECK( RemoveAllSubstrings("one;two;three;four", ";") == "onetwothreefour" );
	CHECK( RemoveAllSubstrings("Eggs, Milk, Bread, Cheese", ", ") == "EggsMilkBreadCheese" );
}

TEST_CASE( "All strings in vector are joined with glue", "[join]" ) 
{

	CHECK( Join({"a", "b", "c"}, ",") == "a,b,c" );
	CHECK( Join({"Hello", "World!"}, " ") == "Hello World!" );
	CHECK( Join({"one", "two", "three", "four"}, ";") == "one;two;three;four" );
	CHECK( Join({"Eggs", "Milk", "Bread", "Cheese"}, ", ") == "Eggs, Milk, Bread, Cheese" );
}

TEST_CASE( "Multiples of n up to n*m are generated", "[multiples]" ) 
{
	CHECK( Multiples(2, 10) == std::vector<int>{2, 4, 6, 8, 10, 12, 14, 16, 18, 20} );
	CHECK( Multiples(3, 6) == std::vector<int>{3, 6, 9, 12, 15, 18} );
	CHECK( Multiples(10, 4) == std::vector<int>{10, 20, 30, 40} );
	CHECK( Multiples(7, 2) == std::vector<int>{7, 14} );
}

TEST_CASE( "Sign of number is determined", "[sign]" ) 
{
	CHECK( Sign(-5) == -1 );
	CHECK( Sign(-523983) == -1 );
	CHECK( Sign(0) == 0 );
	CHECK( Sign(10) == 1 );
	CHECK( Sign(123456789) == 1 );
}