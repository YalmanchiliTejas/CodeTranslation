#include<map>
#include<cstdio>
#include<string>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

struct Idol{
	int vote;
	bool love;
	string name;
	bool operator<(const Idol &I)const{
		if(vote!=I.vote) return vote>I.vote;
		return name<I.name;
	}
};

int main(){
	for(int n,m,k,l;scanf("%d%d%d%d",&n,&m,&k,&l),n;){
		map<string,int> f;
		static Idol I[100000];
		rep(i,n){
			char s[11]; scanf("%s%d",s,&I[i].vote);
			I[i].name=s;
			f[s]=i;
			I[i].love=false;
		}
		rep(i,m){
			char s[11]; scanf("%s",s);
			I[f[s]].love=true;
		}
		sort(I,I+n);

		int lo=0,hi=k;
		while(lo<hi){
			int mi=(lo+hi+1)/2;

			int thr=n-1,cnt=0;
			rep(i,n) if(!I[i].love) {
				if(cnt==k-mi){ thr=i; break; }
				cnt++;
			}

			cnt=0;
			int v=l;
			rep(i,n) if(I[i].love) {
				int tmp;
				if(i>thr) tmp=I[thr].vote-I[i].vote+(I[thr].name<I[i].name?1:0);
				else      tmp=0;

				if(v>=tmp) v-=tmp, cnt++;
				else break;
			}

			if(cnt>=mi) lo=mi; else hi=mi-1;
		}

		printf("%d\n",lo);
	}

	return 0;
}