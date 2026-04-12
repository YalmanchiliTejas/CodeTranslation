//おまじない
//#include <bits/stdc++.h>
#include <iostream>
#include<iomanip>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout << "YES"<<endl;
#define No cout << "No"<<endl;
#define Yes cout << "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<int,int>
#define space ‘ ‘
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

const int maxn = 100000;

int main(){
  ll n;
  ll ans = 0;
  ll num[maxn];
  ll b_n;
  ll b_sum=0;
  ll s_sum=0;

  cin >> n;
  rep(i,n)cin >> num[i];

  sort(num,num+n);
  reverse(num,num+n);
    
    int _n = (n+1)/2;
    
    if(n%2==0){
        ll sub_ans = 0;
        rep(i,_n){
            if(i==_n-1)sub_ans += num[i];
            else sub_ans += num[i]*2;
        }
        rep(i,n-_n){
            if(i==n-_n-1)sub_ans-=num[n-1-i];
            else sub_ans-= num[n-1-i]*2;
        }
        ans = sub_ans;
    }else{
        ll sub_ans_1 = 0;
        ll sub_ans_2 = 0;
        rep(i,_n){
            if(i<_n-2)sub_ans_1-=num[n-1-i]*2;
            else sub_ans_1 -= num[n-1-i];
        }
        rep(i,n-_n)sub_ans_1 += num[i]*2;
        
        rep(i,n-_n)sub_ans_2-=num[n-1-i]*2;
        rep(i,_n){
            if(i<_n-2)sub_ans_2+=num[i]*2;
            else sub_ans_2+=num[i];
        }
        
        ans = max(sub_ans_1,sub_ans_2);
    }
    

    cout << ans<<endl;

  return 0;
}
