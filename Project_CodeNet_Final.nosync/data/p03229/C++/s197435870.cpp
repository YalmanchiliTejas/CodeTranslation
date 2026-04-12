#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
#define INF 1000000007
#define LINF 100000000000000007
#define MOD 1000000007
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
using namespace std;

int n,k;
deque<int> d,e;
signed main(){
    
    cin>>n;
    rep(i,n){
    	int a;
    	cin>>a;
    	d.push_back(a);
    }
    sort(d.begin(),d.end());
    e=d;
    deque<int> da,ea;
    da.push_back(d[n-1]);
    d.pop_back();
    ea.push_back(e[0]);
    e.pop_front();
    for(int i=0;d.size();i++){
    	if(d.size()==1){
    		if(abs(d[0]-da[0])<abs(d[0]-da[da.size()-1])){
    			da.push_back(d[0]);
    		}
    		else{
    			da.push_front(d[0]);
    		}
    		break;
    	}
    	if(i%2==0){
    		da.push_back(d[0]);
    		da.push_front(d[1]);
    		d.pop_front();d.pop_front();
    	}
    	else{
    		da.push_back(d[d.size()-1]);
    		da.push_front(d[d.size()-2]);
    		d.pop_back();d.pop_back();
    	}
    }
    
    for(int i=0;e.size();i++){
    	if(e.size()==1){
    		if(abs(e[0]-ea[0])<abs(e[0]-ea[ea.size()-1])){
    			ea.push_back(e[0]);
    		}
    		else{
    			ea.push_front(e[0]);
    		}
    		break;
    	}
    	if(i%2==1){
    		ea.push_back(e[0]);
    		ea.push_front(e[1]);
    		e.pop_front();e.pop_front();
    	}
    	else{
    		ea.push_back(e[e.size()-1]);
    		ea.push_front(e[e.size()-2]);
    		e.pop_back();e.pop_back();
    	}
    }
    
    int ans=0,ans2=0;
    for(int i=1;i<n;i++){
    	ans+=abs(da[i-1]-da[i]);
    	ans2+=abs(ea[i-1]-ea[i]);
    }
    /*rep(i,n)cout<<da[i]<<" ";
    cout<<endl;
    rep(i,n)cout<<ea[i]<<" ";
    cout<<endl;*/
    cout<<max(ans,ans2)<<endl;
}
