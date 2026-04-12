#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef pair<int, int> P;
int N,A;
vector<P> Col;
int ans;
int main()
{
	while (true){
		Col.clear();
		ans = 0;
		scanf("%d", &N);
		if (N == 0)break;
		scanf("%d", &A);
		Col.push_back(P(A, 1));
		for (int i = 1; i < N; i++){
			scanf("%d", &A);
			if ((i & 1) == 0){
				if (Col[Col.size() - 1].first == A){
					Col[Col.size() - 1].second++;
				}
				else{
					Col.push_back(P(A, 1));
				}
			}
			else{
				if (Col[Col.size() - 1].first == A){
					Col[Col.size() - 1].second++;
				}
				else{
					P p = Col[Col.size() - 1];
					Col.erase(Col.end() - 1, Col.end());
					if (Col.size() == 0){
						Col.push_back(P(A, p.second + 1));
					}
					else{
						Col[Col.size() - 1].second += (p.second + 1);
					}
				}
			}
		}
		for (int i = 0; i < Col.size(); i++){
			if (Col[i].first == 0)ans += Col[i].second;
		}
		printf("%d\n", ans);
	}
	return 0;
}