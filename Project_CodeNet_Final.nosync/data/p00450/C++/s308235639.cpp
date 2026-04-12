#include <cstdio>
#include <vector>
using namespace std;

int n;
int c[100000];
vector<int> v, w;

int main(){
	while(1){
		scanf("%d", &n);
		if(n == 0) return 0;
		v = w;
		int t, s;
		scanf("%d", &t);
		if(t == 0){
			v.push_back(1);
		}else{
			v.push_back(0);
			v.push_back(1);
		}
		for(int i=0; i<n-1; ++i){
			scanf("%d", &s);
			if(t == s) ++v[v.size()-1];
			else{
				if(i % 2 == 0){
					if(v.size() == 1){
						v.push_back(v[0]);
						++v[1];
						v[0] = 0;
					}else{
						v[v.size()-2] += v[v.size()-1];
						++v[v.size()-2];
						v.pop_back();
					}
				}else{
					v.push_back(1);
				}
			}
			t = s;
/*			for(int j=0; j<v.size(); ++j){
				printf("%d\t", v[j]);
			}
			printf("\n");
*/		}

		int ans = 0;
		for(int i=0; i<v.size(); i++){
//			printf("%d\t", v[i]);
			if(i % 2 == 1) continue;
			ans += v[i];
		}
//		printf("\n");
		printf("%d\n", ans);
	}
}