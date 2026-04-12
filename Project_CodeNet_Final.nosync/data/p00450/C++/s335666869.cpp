#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	for(int n;scanf("%d",&n),n;){
		vector<int> a,b;
		for(int i=0;i<n;i++){
			int c; scanf("%d",&c);
			if(i&1){
				int cnt=0;
				while(a.size()>0 && a.back()!=c){
					cnt+=b.back();
					a.pop_back();
					b.pop_back();
				}
				if(a.size()==0){
					a.push_back(c);
					b.push_back(0);
				}
				b.back()+=cnt+1;
			}
			else{
				int cnt=0;
				while(a.size()>0 && a.back()==c){
					cnt+=b.back();
					a.pop_back();
					b.pop_back();
				}
				a.push_back(c);
				b.push_back(cnt+1);
			}
		}
		int res=0;
		for(int i=0;i<a.size();i++)
			if(a[i]==0)
				res+=b[i];
		printf("%d\n",res);
	}
	
	return 0;
}