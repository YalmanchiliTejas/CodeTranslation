#include<stdio.h>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
char in[110];
int e[110000];
int f[110000];
int v[110000];
int y[110000];
pair<int,int> t[110000];
pair<int,int> s[110000];
int main(){
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d),a){
		map<string,int>m;
		for(int i=0;i<a;i++){
			scanf("%s%d",in,e+i);
			string tmp=in;
			m[tmp]=i;
			v[i]=0;
		}
		int now=0;
		for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
			y[(*it).second]=now++;
		}
		for(int i=0;i<b;i++){
			scanf("%s",in);
			string tmp=in;
			f[i]=m[tmp];
			v[f[i]]=1;
		}
		int sz=0;
		for(int i=0;i<a;i++){
			if(!v[i])s[sz++]=make_pair(-e[i],y[i]);
		}
		std::sort(s,s+sz);
		for(int i=0;i<b;i++)t[i]=make_pair(-e[f[i]],y[f[i]]);
		std::sort(t,t+b);
		int L=0;
		int R=min(b,c)+1;
		while(L+1<R){
			int M=(L+R)/2;
			int rem=c-M;
			if(c-M>=sz){
				L=M;continue;
			}
			long long pr=0;
			for(int i=0;i<M;i++){
				int tmp=t[i].first-s[rem].first;
				if(t[i].second>s[rem].second)tmp++;
				pr+=max(0,tmp);
			}
		//	printf("%d: %lld\n",M,pr);
			if(pr<=d)L=M;
			else R=M;
		}
		printf("%d\n",L);
	}
}