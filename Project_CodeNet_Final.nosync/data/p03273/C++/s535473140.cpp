#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define be begin
#define en end
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ALL(a) (a).be() , (a).en()
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)        //repeat n times
#define REP2(i,s,n) for(int (i)=(s);(i)<(n);(i)++)   //repeat from s to n 
#define REPD(i,n) for(int (i)=(n);(i)>=0;(i)--)      //repeat from n to 0
#define REPD2(i,s,e) for(int (i)=(s);(i)>=(e);(i)--) //repeat from s to e
#define RANGE(i,v) for(auto &(i):v)                  //repeat range
#define ASIZE(a) (sizeof(a) / sizeof(a[0]))          //array size

using LL = long long;

template<typename T> using V = vector< T >;
using Vi = V<int>;
using Vll = V<LL>;
using Vs = V<string>;

int main(){
    int H,W;
    cin>>H>>W;
    V<V<char>> a(H,V<char>(W));
    Vi cnt_H(H);
    Vi cnt_W(W);
    REP(i,H){
        REP(j,W){
            cin>>a[i][j];
            if(a[i][j]=='.'){
                cnt_H[i]++;
                cnt_W[j]++;
            }
        }
    }

    REP(i,H){
        if(cnt_H[i]==W) continue;
        REP(j,W){
            if(cnt_W[j]==H) continue;
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}