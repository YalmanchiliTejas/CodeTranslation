#include <iostream>
#include <string>
using namespace std;

int N; string S;
bool ani[100010];
bool greedy(bool f1, bool f2){
    ani[0]=f1;
    ani[1]=f2;
    for(int i=2; i<N; ++i){
        ani[i]=((S[i-1]=='o')^ani[i-1])^ani[i-2];
    }
    return (ani[1]^ani[N-1])^(S[0]=='o')==ani[0] && (ani[N-2]^ani[0])^(S[N-1]=='o')==ani[N-1];
}
int main() {
	cin >> N >> S;
	bool flag=false;
	for(int i=0; i<4; ++i){
	    if(greedy(i<2, i%2<1)){
	        flag=true;
	        break;
	    }
	}
	if(flag){
	    for(int i=0; i<N; ++i) cout << (ani[i] ? 'S' : 'W');
	    cout << endl;
	}
	else cout << -1 << endl;
	return 0;
}
