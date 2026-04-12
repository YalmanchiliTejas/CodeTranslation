   #include <bits/stdc++.h>
 
 #define int long long
 #define pa pair<int,int>
  #define  mp make_pair
  #define  pb push_back
 using namespace std;





 signed main(){
 	
 
    cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
 	cin>>n;
 	vector<int> ve(n);
 	for(int i=0;i<n;i++)cin>>ve[i];
 	map<int,int>ma;
 	for(int i=0;i<n;i++){
 		int y=ve[i];
 		int yy=y;
 		for(int j=2;j*j<=y;j++)if(yy%j==0){
 			ma[j]+=y;
 			while(yy%j==0)yy/=j;
 		}
 		if(yy>1)ma[yy]+=y;
 	}
 	int ans=0;
 	for(auto it=ma.begin();it!=ma.end();it++)ans=max(ans,(*it).second);
 	cout<<ans<<endl;
return 0;

 }
