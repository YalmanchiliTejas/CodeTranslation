#include<cstdio>
#include <cstring>
#include<cstdlib>
#include <stack>

using namespace std;

int dat[100005],n;


int main(void){

	while(1){
		scanf("%d",&n);
		if(n==0)break;
		for(int i=1;i<=n;i++){
			scanf("%d",&(dat[i]));
		}
		
		stack<int> st;
		st.push(1);
		int topcl=dat[1];
		for(int i=2;i<=n;i++){
			if(i%2==1){
				if(topcl==dat[i]){
					int p=st.top();
					st.pop();
					st.push(p+1);
				}
				else{
					st.push(1);
					topcl=1-topcl;
				}
			}
			else{
				if(topcl==dat[i]){
					int p=st.top();
					st.pop();
					st.push(p+1);
				}
				else{
					int p=st.top();
					st.pop();
					if(!st.empty()){
						int q=st.top();
						st.pop();
						st.push(p+q+1);
					}
					else{
						st.push(p+1);
					}
					topcl=1-topcl;
				}
			}
		}
		
		int ans=0;
		while(!st.empty()){
			if(topcl==0){
				ans+=st.top();
			}
			st.pop();
			topcl=1-topcl;
		}
		
		printf("%d\n",ans);

	}
	return 0;
}