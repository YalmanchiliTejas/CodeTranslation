#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)
using P =pair<ll,ll>;

ll ketasu(ll a){
   ll num=1;
   while(a/10){
       num++;
       a/=10;
   }
   return num;
}

ll gcd(ll a,ll b){return b ? gcd(b,a%b) :a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

ll kosuu(ll a){
    ll sum=0;
    for(ll i=1;i*i<=a;i++){
        if(a%i==0){
            if(a!=1&&i*i!=a){
            sum+=2;
            }else{
             sum++;   
            }
        }
    }
    return sum;
}

ll n;



    vector<pair<ll,ll>>p;
void fs(ll a){
    for(ll i=2;i*i<=n;i++){
        ll cnt=0;
        while(n%i==0){
            n/=i;
            cnt++;
        }
        p.emplace_back(i,cnt);
    }
    return;
}


ll di[]={1,0,-1,0};
ll dj[]={0,-1,0,1};
int main(){
int N;
	cin >> N;
	vector<int> A(N);
	vector<long long> B(N + 1, 0); //累積和テーブル
	int mod = 1000000007;
 
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		B[i + 1] = B[i] + A[i];
	}
 
	long ans = 0;
 
	//i について全探索する
	for (int i = 0; i < N; i++)
	{
		//累積和を使ってA[i+1] + ... + A[N] を求める
		long long sum = (B[N] - B[i + 1]) % mod;
 
		ans += A[i] * sum;
		ans %= mod;
	}
 
	cout << ans << endl;
}


