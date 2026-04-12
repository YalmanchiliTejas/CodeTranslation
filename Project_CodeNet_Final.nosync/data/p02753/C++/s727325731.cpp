#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
//#include <functional> // for less
//using namespace __gnu_pbds;

#define max_(x, y) (((x) > (y)) ? (x) : (y))
#define min_(x, y) (((x) < (y)) ? (x) : (y))
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
#define Mx 200001
#define inf 1e15
const int MOD = 1e9+7;
const double pi = 2 * acos (0.0);

/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/


typedef long long  L;
//typedef tree<L,null_type,less<L>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

L a1,a2,a3,b1,b2,b3,c,c1,c2,c3,d,d1,d2,d3,d4,d5,e1,e2,e3,f,h,k,l,m,n,m1,m2,n1,n2,o,p,p1,p2,p3,p4,q,q1,q2,q3,q4,r,s,t,
u,v,x,y,z,sum,mx=-inf,mn=inf,flg,flg1,flg2,id1,id2,id3,id4,lim;

//double rat;
L A[Mx+5],B[Mx+5];

char str[Mx];

//struct node{L nid,nv;node(L nid_,L nv_){nid=nid_;nv=nv_;}};
//vector<node>V;
void solve(){
	if(str[0]!=str[1] || str[0]!=str[2] || str[1]!=str[2]){
    	printf("Yes");
    }else{
      printf("No");
    }
}
int main()
{
    scanf("%s",str);
  	solve();
    return 0;
}
/// lld I64d push_back() top() pop() insert() upper_bound() lower_bound() memset() max() min() scanf continue
