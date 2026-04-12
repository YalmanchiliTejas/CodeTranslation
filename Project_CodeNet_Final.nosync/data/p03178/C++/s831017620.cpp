#include "bits/stdc++.h"
using namespace std;
#define PIGRECO 3.141592653589793
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////
const int mod=1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string k;
    cin>>k;

    int d;
    cin>>d;


    vector<vector<int>>dp(d,vector<int>(2));

    int n=k.length();
    dp[0][0]=1;

    for(int i=0;i<n;i++){

	vector<vector<int>>dp1(d,vector<int>(2));

       for(int j=0;j<d;j++){

	for(bool small:{false,true}){

         for(int digit=0;digit<10;digit++){


                        if(digit>k[i]-'0' && !small){
			    break;
			}


                        dp1[(j+digit)%d][(digit<k[i]-'0') || (small)] = (dp1[(j+digit)%d][(digit<k[i]-'0') || (small)] + dp[j][small])%mod;


		  }



	    }
	}



	dp=dp1;

	debug()<<imie(dp);


    }



        int answer = (dp[0][false] + dp[0][true]) % mod;



        --answer;
    if(answer == -1) {
        answer = mod - 1;
    }
    printf("%d\n", answer);















}
