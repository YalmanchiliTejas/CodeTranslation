#pragma GCC optimize "trapv"
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
//#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,a,n) for(int i=a;i<n;i++)
#define all(v) v.begin(),v.end()
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
const ll mod=1000000007;
int findProductSum(int A[], int n) 
{ 
    // calculating array sum (a1 + a2  ... + an) 
    int array_sum = 0; 
    for (int i = 0; i < n; i++) 
        array_sum = ((array_sum%mod) + (A[i]%mod))%mod; 
  
    // calcualting square of array sum 
    // (a1 + a2 + ... + an)^2 
    int array_sum_square = ((array_sum%mod) * (array_sum%mod))%mod; 
  
    // calcualting a1^2 + a2^2 + ... + an^2 
    int individual_square_sum = 0; 
    for (int i = 0; i < n; i++) 
        individual_square_sum = ((individual_square_sum)%mod + (A[i]*A[i])%mod)%mod; 
  
    // required sum is (array_sum_square - 
    // individual_square_sum) / 2 
    return ((array_sum_square%mod - individual_square_sum%mod + mod)%mod)/2; 
} 
int main()
{
    fio;
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        rep(i,n)
        cin>>a[i];
        ll sum=0,sum1=0;
        for(int i=0;i<n;i++)
        {
            sum=((sum%mod)+(a[i]%mod))%mod;
            sum1=((sum1%mod) + ((a[i]%mod) *(a[i]%mod))%mod)%mod;
        }
        sum=((sum%mod)*(sum%mod))%mod;
        sum=((sum%mod)-(sum1%mod)+mod)%mod;
        sum=((sum)*(500000004))%mod;
        cout<<sum<<endl;
    }
}