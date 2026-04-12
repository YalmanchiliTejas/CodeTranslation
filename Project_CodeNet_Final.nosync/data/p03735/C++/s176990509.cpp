#include <cstdio>
#include <cstdlib>

int N;
int xs[200008];
int ys[200008];
int event[200008];
long long lf=0;
long long rg=0;
long long up=0;
int ind[200008];
int cmp(const void *ka,const void *kb) {
	int a=*(int *)ka;
	int b=*(int *)kb;
	if(xs[a]!=xs[b]) return xs[b]-xs[a];
	return a-b;
}
int main() {
	scanf("%d",&N);
	for(int i=0;i<N;i++) {
		scanf("%d%d",&xs[i],&ys[i]);
		if(xs[i]<ys[i]) {
			int temp=xs[i];
			xs[i]=ys[i];
			ys[i]=temp;
		}
	}
	int ymin_ind=0;
	for(int i=0;i<N;i++) if(ys[i]<ys[ymin_ind]) ymin_ind=i;
	int ind_list=0;
	for(int i=0;i<N;i++) {
		if(xs[i]>xs[ymin_ind]) {
			//add to ind
			ind[ind_list++]=i;
		} else {
			//it is optimal
			if(lf<xs[ymin_ind]-xs[i]) lf=xs[ymin_ind]-xs[i];
		}
		if(up<ys[i]-ys[ymin_ind]) up=ys[i]-ys[ymin_ind];
	}
	qsort(ind,ind_list,sizeof(int),cmp);
	long long sol=1000000007;
	sol*=sol;
	for(int i=0;i<ind_list;i++) {
		int now=ind[i];
		long long rg_now=rg;
		if(rg_now<xs[now]-xs[ymin_ind]) rg_now=xs[now]-xs[ymin_ind];
		if(sol>(lf+rg_now)*up) sol=(lf+rg_now)*up;
		//reverse
		if(up<xs[now]-ys[ymin_ind]) up=xs[now]-ys[ymin_ind];
		if(ys[now]>xs[ymin_ind]) {
			if(rg<ys[now]-xs[ymin_ind]) rg=ys[now]-xs[ymin_ind];
		} else {
			if(lf<xs[ymin_ind]-ys[now]) lf=xs[ymin_ind]-ys[now];
		}
	}
	if(sol>(lf+rg)*up) sol=(lf+rg)*up;
	printf("%lld\n",sol);
	return 0;
}
