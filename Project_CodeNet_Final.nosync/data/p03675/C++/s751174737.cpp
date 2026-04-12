#include <iostream>
    #include <deque>
    using namespace std;
     
    int main(){
      int n, a;
      cin >> n;
      deque<int> x;
      bool f = 1;
      for(int i = 0; i < n; i++){
        cin >> a;
        if(f) x.push_back(a);
        else x.push_front(a);
        f = !f;
      }
      if(f){
        for(auto& i : x) cout << i << ' ';
      } else {
        for(int i = x.size()-1; i >= 0; i--) cout << x[i] << ' ';
      }
    }
