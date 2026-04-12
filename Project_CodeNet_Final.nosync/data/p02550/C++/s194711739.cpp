#include<bits/stdc++.h>
using namespace std;

int main(){
	long long N,X,M;
	cin >> N >> X >> M;
	long long ans=X,tmp=X,tmp2;
	map<long long,long long> mems;
	mems[X]=0;
	vector<long long> loopsum;
	loopsum.push_back(X);
	for(long long loop=1;loop<N;loop++){
		tmp2=(tmp*tmp)%M;
		tmp=tmp2;
		if(tmp==0){
			break;
		}else if(mems.count(tmp)){
			long long looplg=loop-mems[tmp];
			tmp2=loopsum[loop-1];
			if(mems[tmp])
				tmp2-=loopsum[mems[tmp]-1];
			ans+=tmp2*((N-loop)/looplg);
			if((N-loop)%looplg){
				ans+=loopsum[mems[tmp]+(N-loop)%looplg-1];
				if(mems[tmp])ans-=loopsum[mems[tmp]-1];
			}
			break;
		}else{
			loopsum.push_back(loopsum[loop-1]+tmp);
			mems[tmp]=loop;
			ans+=tmp;
		}
	}
	cout << ans << endl;
	return 0;
}