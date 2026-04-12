#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
char str[310000];
set<int>S;
int segtree[1048576];
int getmin(int a,int b,int c,int d,int e,int f){
	if(d<a||b<c||c>d)return 1000000007;
	if(c<=a&&b<=d)return f+segtree[e];
	return min(getmin(a,(a+b)/2,c,d,e*2,f+segtree[e]),getmin((a+b)/2+1,b,c,d,e*2+1,f+segtree[e]));
}
void add(int a,int b,int c,int d,int e,int f){
	if(c>d)return;
	if(d<a||b<c)return ;
	if(c<=a&&b<=d){
		segtree[e]+=f;
		return;
	}
	add(a,(a+b)/2,c,d,e*2,f);
	add((a+b)/2+1,b,c,d,e*2+1,f);
	if(segtree[e*2]>0&&segtree[e*2+1]>0){
		int val=min(segtree[e*2],segtree[e*2+1]);
		segtree[e]+=val;
		segtree[e*2]-=val;
		segtree[e*2+1]-=val;
	}
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	scanf("%s",str);
	for(int i=0;i<a;i++)if(str[i]==')')S.insert(i);
	int now=0;
	for(int i=0;i<a;i++){
		if(str[i]=='(')now++;
		else now--;
		add(0,524287,i+1,i+1,1,now);
	}
	for(int i=0;i<b;i++){
		int c;scanf("%d",&c);c--;
		if(str[c]=='('){
			S.insert(c);
			str[c]=')';
			int at=*(S.begin());
			printf("%d\n",at+1);
			str[at]='(';
			S.erase(at);
			add(0,524287,at+1,c,1,2);
		}else{
			S.erase(c);
			str[c]='(';
			add(0,524287,c+1,a,1,2);
			int L=-1;
			int R=c;
			while(L+1<R){
				int M=(L+R)/2;
				int val=getmin(0,524287,M+1,c+1,1,0);
				if(val>=2)R=M;
				else L=M;
			}
			printf("%d\n",R+1);
			str[R]=')';
			S.insert(R);
			add(0,524287,R+1,a,1,-2);
		}
	}
	
}