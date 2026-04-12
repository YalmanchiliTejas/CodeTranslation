#include<iostream>
    using namespace std;
    int main()
    {
      char c;
      std::cin >> c;

      if (c == 'a'||c =='e'||c =='i'||c =='u'||c =='o') {
        std::cout << "vowel" << '\n';
        /* code */
      }

      else {
        std::cout << "consonant" << '\n';
      }
        return 0;
      }
