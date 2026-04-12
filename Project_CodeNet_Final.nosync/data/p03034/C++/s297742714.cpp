#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
	cin>>N;
  vector<int> S(N);
	for(int i=0;i<N;i++) cin>>S[i];

  long ans;
	for(int i=1;i<N;i++){//進み幅を試す
		long now=0;
		int L=0,R=N-1;//始点と終点を動かしてみる
		while(R>i&&(R%i||L<R)){//Rがまだ移動できる AND (RがLで移動した点を通過しない OR  LとRが交差するほど進んでいない)
			ans=max(ans,now+=S[L]+S[R]);
			L+=i;R-=i;
		}
	}
	cout<<ans<<endl;
}