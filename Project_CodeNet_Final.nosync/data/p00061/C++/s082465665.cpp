#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	int a,b;
	int c[101];
	vector<int> d;
	while(1){
		scanf("%d,%d",&a,&b);
		if(a == 0 && b == 0){
			break;
		}
		c[a] = b;
		d.push_back(b);
	}
	sort(d.begin(),d.end(),greater<int>());
	d.erase(unique(d.begin(),d.end()),d.end());
	int e;
	while(scanf("%d",&e) != -1){
		printf("%d\n",(int)(lower_bound(d.begin(),d.end(),c[e],greater<int>()) - d.begin() + 1));	
	}
}