#include <iostream>

#define VARIABLE(x) cerr << #x << "=" << x << endl
#define BINARY(x) cerr << #x << "=" << static_cast<bitset<16> >(x) << endl;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)
#define if_range(x, y, w, h) if (0<=x && x<w && 0<=y && y<h)

const int INF = 10000000;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
using namespace std;
typedef pair<int, int> P;

/** Problem0502 : Dice **/

const int North[6] = {2, 1, 5, 3, 0, 4};
const int East[6] = {0, 4, 1, 2, 3, 5};
const int West[6] = {0, 2, 3, 4, 1, 5};
const int South[6] = {4, 1, 0, 3, 5, 2};
const int Right[6] = {1, 5, 2, 0, 4, 3};
const int Left[6] = {3, 0, 2, 5, 4, 1};

int main()
{
	int n;
	while (cin>>n, n) {
		int ans=1;
		int dice[6] = {5, 4, 1, 3, 6, 2};
		int tmp[6] = {5, 4, 1, 3, 6, 2};
		rep(k, n) {
			string s; cin>>s;
			if (s=="North") {
				rep(i, 6)
					dice[i] = tmp[North[i]];
			} else if (s=="East") {
				rep(i, 6)
				dice[i] = tmp[East[i]];
			} else if (s=="West") {
				rep(i, 6)
				dice[i] = tmp[West[i]];
			} else if (s=="South") {
				rep(i, 6)
				dice[i] = tmp[South[i]];
			} else if (s=="Right") {
				rep(i, 6)
				dice[i] = tmp[Right[i]];
			} else if (s=="Left") {
				rep(i, 6)
				dice[i] = tmp[Left[i]];
			}
			
			rep(i, 6) {
				tmp[i] = dice[i];
			}
			
			ans+=dice[2];
		}
		cout << ans << endl;
	}
}