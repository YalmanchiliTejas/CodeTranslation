#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<climits>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define MOD 1000000007
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<unsigned long long> ans(n,0);
    unsigned long long sum = 0;
    for(int i = 0;i<n;i++)
    {
        cin>>ans[i];
    }
    unsigned long long check = 0;
    for(int i = 0;i<n;i++)
    {
       sum = (sum + (ans[i]*check)%MOD)%MOD;
       check  = (check + ans[i])%MOD;
    }

    cout<<sum;
return 0;
}