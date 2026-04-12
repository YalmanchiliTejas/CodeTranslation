#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define MOD 1000000007
#define Long long long 
#define maxn 100003
#define pb push_back
using namespace std;
int par[maxn];
int anc(int p) { 
	if(par[p]==p) return p;
	return par[p] = anc(par[p]);
}
void join(int p, int q){
	par[anc(p)] = anc(q);
}
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<ii> vtxCood1,vtxCood2;
vector<iii> vtxCood;

int n;
main(){	
	int x,y,ans = 0;
	cin >> n;
	 For(i,1,n) par[i]=i;
	For(i,1,n){
		scanf("%d%d",&x,&y);
		vtxCood1.pb(ii(x,i));
		vtxCood2.pb(ii(y,i));
	}
	sort(vtxCood1.begin(), vtxCood1.end());		
	sort(vtxCood2.begin(), vtxCood2.end());		
	For(i,0,n-2){
		vtxCood.pb(iii(vtxCood1[i+1].first-vtxCood1[i].first,ii(vtxCood1[i].second,vtxCood1[i+1].second)));
		vtxCood.pb(iii(vtxCood2[i+1].first-vtxCood2[i].first,ii(vtxCood2[i].second,vtxCood2[i+1].second)));
	}
	sort(vtxCood.begin(), vtxCood.end());		
	
	vector<iii>::iterator it;
    for (it=vtxCood.begin(); it!=vtxCood.end(); it++){
    	int v1 = it->second.first;
    	int v2 = it->second.second;
        if (anc(v1) != anc(v2)){
            join(v1,v2);
            ans += it->first;
        }
    }    
    
	cout << ans;
}