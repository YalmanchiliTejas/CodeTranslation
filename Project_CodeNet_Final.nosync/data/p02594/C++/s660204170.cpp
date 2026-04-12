/*
 
 * This code is written by Sanskar Agarwal
 
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define VPLL vector<PLL>
#define VPII vector<PII>
#define PQ priority_queue<PLL,VPLL, greater<PLL> > 
#define PQI priority_queue<PII,VPII,greater<PII> >
#define UMLL unordered_map<ll,ll>
#define UMII unordered_map<int,int>
#define VI vector<int>
#define VL vector<ll>
#define S second
#define F first
#define PB push_back


int main()
{


    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    int x;
    cin>>x;
    if(x>=30)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}