#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define lli long long int
#define ulli unsigned long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define loop(i,a,b) for(lli i=a;i<b;i++)
#define initialize(array,size,value) for(lli i=0;i<size;i++) array[i]=value
#define couta(array,size) for(lli i=0;i<size;i++) cout<<array[i]<<" "
#define vl vector<lli>
#define vp vector< pair <lli,lli> >
#define sl set<lli>
#define msp multiset < pair < long long , long long > > S;
#define pll pair<lli, lli>
#define mll map<lli, lli>              //for( map<lli, lli>::iterator i=result.begin();i!=result.end();i++)cout<<i->fi<<" "<<i->se<<endl;
#define mvl map<lli, vl>
#define umll unordered_map<lli, lli>
#define vt vector<pair<lli, pll >  >
#define vf vector<pair<pll,pll > >
#define qu queue<lli>
//#define pq priority_queue<lli>
#define dq deque <lli>
#define ptr vector<lli>::iterator
#define bs(array,x) binary_search(array.begin(),array.end(),x)
#define lb(array,x) lower_bound(array.begin(),array.end(),x)
#define ub(array,x) upper_bound(array.begin(),array.end(),x)
#define nobw(array,i,j) upper_bound(array.begin(), array.end(), j)-lower_bound(array.begin(), array.end(), i) //number of numbers between i & j
#define vc clear()
#define endl '\n'
#define sp system("pause");
#define INF 9223372036854775807
#define MINF -9223372036854775808
typedef tree<pll,null_type,less<pll>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
int ms(int arr[], int n) 
{ 
    multiset<int> last; 
    for (int i = 0; i < n; i++) { 
        multiset<int>::iterator it = last.lower_bound(arr[i]); 
        if (it == last.begin()) 
            last.insert(arr[i]); 
  
        else { 
            it--; 
        last.erase(it); // erase the largest element smaller than arr[i] 
            last.insert(arr[i]); // and replace it with arr[i] 
        } 
    } 
    return last.size(); // our answer is the size of last 
} 
  
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<ms(a,n);

    return 0;
}
