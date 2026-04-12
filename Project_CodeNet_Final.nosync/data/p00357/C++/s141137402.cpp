#include<iostream>
#include<algorithm>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;

queue<int> Q;
int d[300010],n;

int p[300010];
bool Fcan(){
    lol(i,n)p[i]=max(1,i);
    while(!Q.empty())Q.pop();
    Q.push(0);
    while(!Q.empty()){
	int x=Q.front();
	Q.pop();
	//cout<<x<<" ";
	int a=max(0,x-d[x]/10),b=a,t;
	while(p[a]!=a)a=p[a];
	while(p[b]!=b)t=p[b],p[b]=a,b=t;
	
	while(true){
	    if(a>x+d[x]/10)break;
	    if(a==n-1)return true;
	    Q.push(a);
	    p[a]=a+1;
	    a=p[a+1];
	}
    }
    return 0;
}

int main(){
    cin>>n;
    lol(i,n){
	cin>>d[i];
	//d[i]=10;
    }
    bool ok=Fcan();
    lol(i,n/2)swap(d[i],d[n-1-i]);
    ok&=Fcan();
    cout<<(ok?"yes":"no")<<endl;
    return 0;
}

