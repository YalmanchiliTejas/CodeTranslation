#include<iostream>
#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define endl "\n"
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n; cin>>n;
 
    vector<int> a(n);
    deque<int> q;
    rep(i,n)cin>>a[i];
    rep(i,n){
        if(i%2==0){
            q.push_back(a[i]);
        }
        else{
            q.push_front(a[i]);
        }
    }
    for(int i=0;i<n;i++){
        int ans = 0;
        if(n%2==0){
            ans = q.front();
            q.pop_front();
        }
        else{
            ans = q.back();
            q.pop_back();
        }
        cout<< ans << " ";
    }  
    cout<<endl;
        


}