#include<atcoder/all>
using namespace std;
using namespace atcoder;
int t,a,b;
int op(int a,int b){return max(a,b);}
int e(){return-1;}
bool f(int X){return b>X;}
main()
{
	int N,Q;
	cin>>N>>Q;
	vector<int>A(N);
	for(int&a:A)cin>>a;
	segtree<int,op,e>P(A);
	for(;Q--;)
	{
		cin>>t>>a>>b;
		if(t==1)P.set(a-1,b);
		else if(t==2)cout<<P.prod(a-1,b)<<endl;
		else cout<<P.max_right<f>(a-1)+1<<endl;
	}
}
