using namespace std;
int main(){
	int n,t;
	while(cin>>n,n){
		int mx=0,mn=1000,s=0;
		for(int i=0;i<n;i++){
			cin>>t,s+=t;
			if(t>mx)mx=t;
			if(t<mn)mn=t;
		}
		cout<<(s-mx-mn)/(n-2)<<endl;
	}
	return 0;
}