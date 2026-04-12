#include <cstdio>
#include <stack>
#include <iostream>

using namespace std;

void calc(int n){
    int in,l,c,s,ans=0;
    stack<int> st;

    scanf("%d",&s);
    l=s;
    st.push(1);

    for(int i=1;i<n;i++){
        scanf("%d",&in);
        if(i%2==1){
            if(in!=l){
                c=0;
                c+=st.top();
                st.pop();
            
                if(st.size()>=1)st.top()+=c+1;
                else st.push(c+1);
                
            }else{
                st.top()++;
            }
        }else{
            if(in!=l){
                st.push(1);
            }else{
                st.top()++;
            }
        }
        l=in;
    }

    for(int i=0;!st.empty();i++){
        if((l+i)%2==0){
            ans+=st.top();
        }
        st.pop();
    }

    printf("%d\n",ans);

    return;
}

int main(){
    int n;
    
    while(1){
        scanf("%d",&n);
        
        if(n==0) break;
        
        calc(n);
    }
    
    return 0;
}
    