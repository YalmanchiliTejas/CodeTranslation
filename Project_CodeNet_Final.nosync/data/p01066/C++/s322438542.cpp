#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef P Vector;

typedef pair<P,Vector> Line;

int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int dot(Vector a,Vector b){
	return a.first*a.second+b.first*b.second;
}

int cross(Vector a,Vector b){
	return a.first*b.second-b.first*a.second;
}

int n;
int x[9],y[9];
int ans;
vector<Line> li;
bool po=false;

bool same(Line a,Line b){
	if(a.second.first==0){
		if(a.first.first==b.first.first && b.second.first==0)return true;
	}else if(a.second.second==0){
		if(a.first.second==b.first.second && b.second.second==0)return true;
	}else{
		int diff=b.first.first-a.first.first;
		if(diff%a.second.first!=0)return false;
		int bi=diff/a.second.first;
		if(cross(a.second,b.second)==0 && a.first.second+bi*a.second.second==b.first.second)return true;
	}
	return false;
}

void dfs(int bit){
	//printf("%d\n",bit);
	if(bit==(1<<n)-1){
		ans=min(ans,(int)li.size());
		return;
	}
	if(ans<=li.size())return;
	for(int i=0;i<n;i++){
		if(bit>>i & 1){
			for(int j=0;j<n;j++){
				if(!(bit>>j & 1)){
					P mid=P((x[i]+x[j])/2,(y[i]+y[j])/2);
					Vector vec=Vector(y[j]-y[i],x[i]-x[j]);
					int g=gcd(abs(y[j]-y[i]),abs(x[i]-x[j]));
					//printf("%d %d %d\n",abs(y[j]-y[i]),abs(x[i]-y[j]),g);
					vec.first/=g;
					vec.second/=g;
					bool flag=false;
					for(int k=0;k<li.size();k++){
						if(same(li[k],Line(mid,vec))){
							flag=true;
							break;
						}
					}
					if(!flag){
						li.push_back(Line(mid,vec));
					}
					dfs(bit+(1<<j));
					if(!flag){
						li.pop_back();
					}
				}
			}
		}
	}
}

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
		x[i]*=2;
		y[i]*=2;
	}
	vector<Line> li;
	bool po=false;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			P mid=P((x[i]+x[j])/2,(y[i]+y[j])/2);
			Vector vec=Vector(y[j]-y[i],x[i]-x[j]);
			int g=gcd(abs(y[j]-y[i]),abs(x[i]-x[j]));
			vec.first/=g;
			vec.second/=g;
			for(int k=0;k<n;k++){
				if(k==i)continue;
				for(int l=k+1;l<n;l++){
					if(l==j)continue;
					P mid2=P((x[k]+x[l])/2,(y[k]+y[l])/2);
					Vector vec2=Vector(y[l]-y[k],x[k]-x[l]);
					g=gcd(abs(y[l]-y[k]),abs(x[l]-x[k]));
					vec2.first/=g;
					vec2.second/=g;
					if(same(Line(mid,vec),Line(mid2,vec2)))po=true;
				}
			}
		}
	}
	if(!po){
		printf("%d\n",n-1);
		return 0;
	}
	ans=n-2;
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
