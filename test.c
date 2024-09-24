/*
 * hasUniqueChars.c
 * 
 * Contains a variety of string tests for the function in hasUniqueChars.c
 * 
 * Author: Elisa Avalos
 */

#include <stdio.h>    // printf
#include <stdbool.h>  // to define a boolean type and true, false
#include <string.h>   // strcpy  to copy a string
#include <assert.h>


// declaration of function from hasUniqueChars.c
bool hasUniqueChars(char * inputStr);


int main() {

  // ------------------------------------------------------------
  // Examples of declaring string constants
  /* Example 1 */
  char string1[] = "A string declared as an array.\n";

  /* Example 2 */
  char *string2 = "A string declared as a pointer.\n";

  /* Example 3 */
  char string3[128];   // can copy in up to 127 characters
                       // chose 128 because it is a multiple of 8 bytes
  strcpy(string3, "A string constant copied in.\n");

  // You can uncomment these to see how the strings were initialized above.
  // Then you can comment these out again once you see that the 
  // strings were created correctly
  // printf ("%s", string1);
  // printf ("%s", string2);
  // printf ("%s", string3);

  // -------------------------------------------------------------
  // Thorough and exhaustive tests of hasUniqueChars()  
  bool ok;    // holds the result of hasUniqueChars(); used in asserts
  
  // Test 1: a test case that should return false because letter characters are duplicated
  strcpy(string3, "This should fail (l and s and i and h)");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  
  // Test 2: This should be true and not fail, but won't work until you
  // complete the hasUniqueChars() function
  strcpy(string3, "abcdefghij");
  ok = hasUniqueChars(string3);
  assert(ok);
  
  
  // Test 3: a test case that should return false because nonletter characters are duplicated
  strcpy(string3, "hello??");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  
  // Test 4: a test case that should return false because nonletter characters are duplicated
  strcpy(string3, "aaaaaaaaaaaaaaaaaaaaaaaah");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  // Test 5: a test case that should return true even though there are multiple space characters
  strcpy(string3, "yo, what is up?");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 6: a test case that should return true because there is no duplicate characters
  strcpy(string3, "okay");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 7: a test case that should return true because there is no duplicate characters (edge cases)
  strcpy(string3, "A~");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 6: a test case that should return true because there is no duplicate characters (edge cases)
  strcpy(string3, "!@");
  ok = hasUniqueChars(string3);
  assert(ok);
  

  // Test 7: a test case that makes sure checkInvalid raises an error due to non-printing characters (escape character)
  strcpy(string3, "\e");
  ok = hasUniqueChars(string3);


  // NOTE: if you add a \n to any tests, this should cause the
  //       exit failure given. Keep this test last so you can check 
  //       that others pass or fail as you expect them to.
  strcpy(string3, "a b cc\n");
  ok = hasUniqueChars(string3);
  // other examples that should fail that you can place in strings
  // are \0 or \t or \r
  // See problem description for more details about escape sequences
  
  return 0;
}