#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	int A,B,C,X,Y;
	cin>>A>>B>>C>>X>>Y;
	int ans = INF;
	if(X>Y){
	swap(X,Y);//X<=Y
	swap(A,B);
	}
	ans = min(ans,A*X+B*Y);
	ans = min(ans,2*X*C +B*(Y-X));
	ans = min(ans,2*Y*C);
	cout<<ans<<endl;
}