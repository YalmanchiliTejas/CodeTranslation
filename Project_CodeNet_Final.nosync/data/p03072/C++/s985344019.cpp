#include "bits/stdc++.h"
#include <boost/multi_array.hpp>
#include <boost/optional.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>

namespace adaptor = boost::adaptors;
using namespace std;

void Main()
{
   int N;
   cin >> N;
   vector<int> H(N);
   for (auto &h : H)
      cin >> h;
   int count = 0;
   int max = 1;
   for (auto h : H)
   {
      if (max <= h)
      {
         max = h;
         count++;
      }
   }
   cout << count << endl;
}

int main()
{
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   Main();
   return 0;
}