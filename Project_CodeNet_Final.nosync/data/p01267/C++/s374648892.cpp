#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int n,a,b,c,x;
	int y[10000];
	while(cin>>n>>a>>b>>c>>x,n){
		rep(i,n)cin>>y[i];
		int f,r=0;
		for(f=0;f<=10000;f++){
			if(x==y[r]){
				r++;
				if(r==n)break;
			}
			x=(a*x+b)%c;
		}
		cout<<(f<=10000?f:-1)<<endl;
	}
	return 0;
}