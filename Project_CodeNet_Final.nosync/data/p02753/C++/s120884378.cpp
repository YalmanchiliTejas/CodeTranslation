//07/03/2020
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define debug printf("Debug\n");

#define ll long long
#define ull unsigned long long

#define pi acos(-1.0)
#define mod 1000000007

#define _fastio  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define in_fre  freopen("in.txt", "r", stdin);
#define out_fre freopen("out.txt", "w", stdout);

struct Node{
    ll val,pos;
};
struct OverloadedNode{
    ll val,pos;
    bool operator < (const OverloadedNode &rhs) const {
        if(val==rhs.val) return pos<rhs.pos;
        else return val<rhs.val;
    }
};

template<typename T> using Pbds=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//typedef tree<OverloadedNode,null_type,less<OverloadedNode>,rb_tree_tag,tree_order_statistics_node_update>OverloadedPbds;

/*Containers*/
//vector<ll>v;
//deque<ll>dq;
//stack<ll>stk;
//map<ll,ll>mp;
//unordered_map<ll,ll>ump;
//set<ll>st;
//multiset<ll>mst;
//unordered_set<ll>ust;
//unordered_multiset<ll>umst;
//priority_queue<ll,deque<ll>,greater<ll>>pq;
//Pbds<ll>ost;
/*OverLoaded Containers*/
//vector<OverloadedNode>v;
//deque<OverloadedNode>dq;
//stack<OverloadedNode>stk;
//map<OverloadedNode,OverloadedNode>mp;
//set<OverloadedNode>st;
//multiset<OverloadedNode>mst;
//priority_queue<OverloadedNode>pq;
//OverloadedPbds oost;
/*Global Variables*/

int main(){
    _fastio
    string s;
    cin>>s;
    if(s[0]==s[1]&&s[1]==s[2]) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;




    return 0;
}
