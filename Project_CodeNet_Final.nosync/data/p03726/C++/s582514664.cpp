#include<cstdio>
const int N=1e5+7;
int n,es[N*2],enx[N*2],e0[N],ep=2,del[N],flag=0;
void f1(int w,int pa){
	for(int i=e0[w];i;i=enx[i]){
		int u=es[i];
		if(u==pa)continue;
		f1(u,w);
	}
	if(!del[w]&&!del[pa])del[w]=del[pa]=1;
	if(!del[w])flag=1;
}
int main(){
	scanf("%d",&n);
	for(int i=1,a,b;i<n;++i){
		scanf("%d%d",&a,&b);
		es[ep]=b;enx[ep]=e0[a];e0[a]=ep++;
		es[ep]=a;enx[ep]=e0[b];e0[b]=ep++;
	}
	del[0]=1;
	f1(1,0);
	puts(flag?"First":"Second");
	return 0;
}