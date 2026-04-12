#include<stack>
#include<cstdio>

#define	mp	make_pair
#define	Clr	first
#define	Num	second

using namespace std;

typedef	pair<int,int>	pii;

int main()
{
	for(int n;scanf("%d",&n),n;){
		stack<pii> st;
		for(int i=0;i<n;i++){
			int a;	scanf("%d",&a);
			if(i&1){
				if(st.top().Clr==a)	st.top().Num++;
				else{
					int num=st.top().Num;	st.pop();
					if(st.empty())	st.push(mp(a,num+1));
					else	st.top().Num+=num+1;
				}
			}
			else{
				if(st.empty() || st.top().Clr!=a)	st.push(mp(a,1));
				else	st.top().Num++;
			}
		}

		int wcnt=0;
		while(!st.empty()){
			if(st.top().Clr==0)	wcnt+=st.top().Num;
			st.pop();
		}
		printf("%d\n",wcnt);
	}

	return 0;
}