#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector> 
#include<limits>
#include<numeric>
#include<type_traits>
#include<math.h>
#include<fstream>
#include<set>
using namespace std;
typedef long long ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define out(str) cout << str << endl
#define ALL(a) (a).begin(),(a).end()
#define INF (1<<29)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int N;
vector<int> ans;

int main(){
    cin>>N;
    int A[N];
    rep(i,N)cin>>A[i];
    ans.push_back(A[0]);
    repi(i,1,N){
        auto it = lower_bound(ALL(ans),A[i]);
        auto be = ans.begin();
        if(it==be){
            ans.insert(be,A[i]);
        }
        else{
            ans[it-be-1]=A[i];
        }
    }
    out(ans.size());


    
}
