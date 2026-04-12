#include<cstdio>
#include<stack>
using namespace std;
typedef pair<int,int> P;
int main(){
    for(;;){
        int n,ins;
        scanf("%d",&n);
        if(n==0)break;
        stack<P> st;
        scanf("%d",&ins);
        st.push(P(ins,1));
        for(int ix=2;ix<=n;ix++){
            scanf("%d",&ins);
            P t=st.top();
            st.pop();
            if(ix%2==0){
                t=P(ins,t.second+1);
            }else{
                if(t.first==ins)t=P(ins,t.second+1);
                else{st.push(t);st.push(P(ins,1));continue;}
            }
            for(;;){
                if(st.empty()){st.push(t);break;}
                P u=st.top();
                st.pop();
                if(u.first==t.first){
                    t=P(t.first,u.second+t.second);
                }else{
                    st.push(u);
                    st.push(t);
                    break;
                }
            }
        }
        int sum=0;
        while(!st.empty()){
            P t=st.top();
            st.pop();
            if(t.first==0)sum+=t.second;
        }
        printf("%d\n",sum);
    }
}