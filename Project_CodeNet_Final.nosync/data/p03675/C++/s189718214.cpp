#include <iostream>
#include <deque>

using namespace std;

int main()
{
  int n;
  cin >> n;
  deque<int> q;
  for(int i = 0; i < n; ++i){
    int tmp;
    cin >> tmp;
    if (i % 2 == 0){
      q.push_back(tmp);
    }else{
      q.push_front(tmp);
    }
  }
  if (n % 2 != 0){
    for(auto it = q.rbegin(); it != q.rend(); ++it){
      if (it != q.rbegin())
        cout << " ";
      cout << *it;
    }
  }else{
    for(auto it = q.begin(); it != q.end(); ++it){
      if (it != q.begin())
        cout << " ";
      cout << *it;
    }
  }
  cout << endl;
  return 0;
}
