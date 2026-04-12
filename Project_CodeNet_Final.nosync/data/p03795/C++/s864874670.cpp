#include <bits/stdc++.h>

#define ipow(a,b)+0.5 (int)pow(a,b)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define fi first
#define se second

#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,a,b) for(int i=a;i<=b;i++)

using namespace std;
typedef long long ll;
typedef long double ld;

class Task
{
public:
    void solve(istream& in,ostream& out)
    {
        int n;
        in>>n;

        out<<n*800-(n/15)*200<<endl;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Task solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in,out);
	out.flush();

    return 0;
}



