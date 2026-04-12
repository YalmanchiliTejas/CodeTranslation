#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    
    ll ans=0,n,x,m;
    cin>>n>>x>>m;
    vector<bool> rem(m+1,false);
    vector<int> nos;
    for(int i=0;i<n;i++){
        if(rem[x]){
            //cout<<"TRUE"<<x<<endl;
            int ind=0;
            for(int i=0;i<nos.size();++i){
                if(nos[i]==x){
                    ind=i;
                    break;
                }
            }
            ll remx=n-i;
            ll q=remx/(nos.size()-ind);
            ll bakki=remx%(nos.size()-ind);
            
            int bakkiind=ind;
            while(bakki--){
                ans+=nos[bakkiind];
                bakkiind++;
            }
            
            ll cs=0;
            for(int j=ind;j<nos.size();++j){
                cs+=nos[j];
            }
            //cout<<endl;
            //cout<<cs<<"----"<<q<<"---"<<ind<<"---"<<bakki<<endl;
            
            ans+=cs*q;
            break;
        }
        
        rem[x]=true;
        nos.push_back(x);
        ans+=x;
        //cout<<x<<" ";
        x=(x%m*x%m)%m;
        
    }
    
    cout<<ans;
    
    
	return 0;
}
