#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
 
class Obj{
  public:
    int a;
    int c;
    Obj(int b, int d){
      a = b;
      c = d;
    }
    bool operator<(const Obj &o) const{
        if(a!=o.a){
            return a<o.a;
        }
      return c<o.c;
    }
};
 
typedef
tree<
  Obj,
  null_type,
  less<Obj>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;
 
int main()
 {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<Obj> li;;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        li.push_back(Obj(x,i));
    }
    ordered_set X;
    for(int i = 0; i<n; i++){
        X.insert(li[i]);
    }
    for(int i = 0; i<n; i++){
        X.erase(X.find(li[i]));
        cout << (*X.find_by_order(n/2-1)).a << endl;
        X.insert(li[i]);
    }
    
}