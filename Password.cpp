#include "Password.h"
#include <string>
#include <cctype>

using std::string;

/*
  The function receives a string counts how many times the same character
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase)
{
  if (phrase.length() == 0)
  {
    return 0;
  }
  int repetition = 1;
  int index = 0;
  while (index < phrase.length() - 1 && phrase[index] == phrase[index + 1])
  {
    repetition++;
    index++;
  }
  return repetition;
}

/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(string str)
{
  bool has_lower = false;
  bool has_upper = false;
  for (char ch : str)
  {
    if (std::islower(ch))
    {
      has_lower = true;
    }
    else if (std::isupper(ch))
    {
      has_upper = true;
    }
  }
  return has_lower && has_upper;
}

/*
  Receives a string and returns a count of how many case-sensitive unique characters there are. 
  If there are duplicate instances of the same character it should only count as a single character. 
  Even if characters look similar, as long as they have distinct ASCII values, they should qualify as unique characters.
*/
unsigned int Password::unique_characters(string str)
{
  // Use a boolean array to track which ASCII characters have been seen
  // ASCII range is 0-255
  bool seen[256] = {false};
  unsigned int count = 0;
  
  for (char ch : str)
  {
    // Convert char to unsigned char to ensure index is in range 0-255
    unsigned char index = static_cast<unsigned char>(ch);
    if (!seen[index])
    {
      seen[index] = true;
      count++;
    }
  }
  
  return count;
}
