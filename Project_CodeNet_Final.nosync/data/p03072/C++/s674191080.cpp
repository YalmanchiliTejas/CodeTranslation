#include<bits/stdc++.h>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for(int i = 0; i < n; i++)std::cin >> a[i];
  int cnt = 0;
  int max = a[0];
  for(int i = 0; i < n; i++){
    if(a[i] >= max)cnt++;
    max = std::max(max, a[i]);
  }
  std::cout << cnt << std::endl;
}