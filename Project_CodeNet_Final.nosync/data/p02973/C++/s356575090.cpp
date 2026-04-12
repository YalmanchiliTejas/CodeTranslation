#include <iostream>
#include <vector>
#include <set>
 
int main()
{
  int n;
  std::cin >> n;
 
  std::vector<int> ax;
  for(int i=0; i<n; i++)
  {
    int a;
    std::cin >> a;
    ax.push_back(a);
  }
 
  std::multiset<int> colorHighs;

  for(int i=0; i<ax.size(); i++)
  {
    if( colorHighs.empty() ) { colorHighs.insert(ax[i]); continue; }

    auto it = colorHighs.lower_bound(ax[i]);
    bool failed = false;
    while( true )
    {
      if( it != colorHighs.end() ) { if( *it < ax[i] ) { break; } }
      if( it == colorHighs.begin() ) { failed = true; break; }
      it--;
    }

    if( failed ) { colorHighs.insert(ax[i]); continue; }
    colorHighs.erase(it);
    colorHighs.insert(ax[i]);
  }
  
  std::cout << colorHighs.size();
}
