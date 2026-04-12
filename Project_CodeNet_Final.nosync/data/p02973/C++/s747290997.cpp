#include <iostream>
#include <set>

int main()
{
   int length;
   std::cin >> length;
   std::multiset<int> ms;
   int value;
   for (int i = 0; i < length; i++) {
      std::cin >> value;
      if (!i) {
         ms.insert(value);
         continue;
      }
      auto itr = ms.lower_bound(value);
      if (itr == ms.begin()) {
         ms.insert(value);
      } else {
         itr--;
         if (*itr != value) {
            ms.erase(itr);
         }
         ms.insert(value);
      }
   }
   std::cout << ms.size() << std::endl;
   return 0;
}
