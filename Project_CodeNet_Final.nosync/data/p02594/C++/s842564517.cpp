#include <iostream>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<long long int,long long int>,null_type,less<pair<long long int,long long int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

void go()
{
    int n;
    cin>>n;
    if(n>=30)
        cout<<"Yes";
    else
        cout<<"No";
}
int main()
{
    FIO;
//    int t;
//    cin>>t;
//    while(t--)
        go();
    return 0;
}
