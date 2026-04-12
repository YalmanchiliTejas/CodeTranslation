#include<iostream>
using namespace std;
int main()
{
	long long a,b;
	cin>>a>>b;
	long long p[55],q[55];
	p[0]=1;
	q[0]=1;
	for(int i=1;i<=50;i++){
		p[i]=p[i-1]*2+3;
		q[i]=q[i-1]*2+1;
	}
	long long ans=0;
	while (b>0){
        if(b==p[a]){
            ans+=q[a];
            b=0;
        }
		else if(b>=p[a]/2+1){
            ans+=q[a-1]+1;
            b-=p[a]/2+1;
        }
		else
        b--;
        a--;
    }
	cout<<ans<<endl;
}