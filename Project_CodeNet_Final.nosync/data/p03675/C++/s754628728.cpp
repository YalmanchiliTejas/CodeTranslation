#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

int main(){
    int n;
    cin >> n;

    list<int> ls;

    bool right = true;
    rep(i,n){
        int x;
        cin >> x;
        if(right){
            ls.push_front(x);
            right = !right;
        }else{
            ls.push_back(x);
            right = !right;
        }
    }

    if(right){
        for(auto it = --ls.end(); it != ls.begin(); it--){
            if(it == --ls.end()) cout << *it;
            else cout << ' ' << *it;
        }
        cout << ' ' << *ls.begin();
    }else{
        for(auto it = ls.begin(); it != ls.end(); it++){
            if(it == ls.begin()) cout << *it;
            else cout << ' ' << *it;
        }
    }
    cout << endl;
}
