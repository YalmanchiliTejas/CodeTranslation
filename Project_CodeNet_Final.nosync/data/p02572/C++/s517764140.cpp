#include <bits/stdc++.h> //C
using namespace std;

//g++ -g -o yourexe yourfile.cpp
//./yourexe < yourinput.in > youroutput.out

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define M 1000000007

#define ll long long
#define ull unsigned long long
#define ld long double
#define vi vector<ll>
#define pi pair<ll, ll>
#define vii vector<pi>
#define vvi vector<vi>
#define pb push_back
#define endl "\n"
#define ff first
#define ss second

#define REP(i, s, e) for (ll i = s; i < e; i++)
#define RREP(i, s, e) for (ll i = s; i > e; i--)

#define all(v) v.begin(), v.end()
#define take(arr,n) REP(i,0,n)cin>>arr[i];
#define print(arr, n) REP(i,0,n)cout<<arr[i]<<" ";
#define printv(v) REP(i,0,v.size())cout<<v[i]<<" ";

ll gcd(ll a, ll b){
  if(a==0)return b;
  return gcd(b%a,a);
}

ll lcm(ll a, ll b){
  return a*b/gcd(a,b);
}

void merge(ll *arr, ll st, ll mid, ll ed, ll maxele){
  ll i=st,j=mid+1,k=st;
  while(i<=mid && j<=ed){
    if(arr[i]%maxele <= arr[j]%maxele){
      arr[k]=arr[k]+(arr[i]%maxele)*maxele;
      k++;
      i++;
    }
    else{
      arr[k]=arr[k]+(arr[j]%maxele)*maxele;
      k++;
      j++;
    }
  }
  while(i<=mid){
    arr[k]=arr[k]+(arr[i]%maxele)*maxele;
    k++;
    i++;
  }
  while(j<=ed){
    arr[k]=arr[k]+(arr[j]%maxele)*maxele;
    k++;
    j++;
  }
  REP(i,st,ed+1)arr[i]=arr[i]/maxele;
}

void mergeSortRec(ll *arr, ll st, ll ed, ll maxele){
  if(st>=ed)return;
  ll mid=(st+ed)/2;
  mergeSortRec(arr,st,mid,maxele);
  mergeSortRec(arr,mid+1,ed,maxele);
  merge(arr,st,mid,ed,maxele);
}

void mergeSort(ll *arr, ll n){
  ll maxele=*max_element(arr,arr+n)+1;
  mergeSortRec(arr,0,n-1,maxele);
}

ll fact(ll n){
  if(n<=1)return 1;
  return ((n%M)*(fact(n-1)%M))%M;
}

int main() {
    fast
    ll t;
    //cin>>t;
    t=1;
    while(t--){
      ll n;
      cin>>n;
      ull arr[n];
      take(arr,n);
      ull dp[n];
      dp[0]=arr[0];
      REP(i,1,n){
        dp[i]=dp[i-1]+arr[i];
      }
      ull sum=0;
      RREP(i,n-1,0){
        sum=(sum%M+(((dp[i]-arr[i])%M)*arr[i]%M)%M)%M;
      }
      cout<<sum;
    }
    return 0;
}
