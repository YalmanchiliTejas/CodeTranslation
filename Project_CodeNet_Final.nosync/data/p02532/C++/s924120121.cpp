#include <iostream>
#include <stack>

using namespace std;

stack<char> s[101];
int main(){
    string op;char c;int st,st2;
    while(cin>>op){
        if(op=="push"){
            cin>>st>>c;
            s[st].push(c);
        } else if(op=="pop"){
            cin>>st;
            cout<<s[st].top()<<endl;
            s[st].pop();
        } else if(op=="move"){
            cin>>st>>st2;
            s[st2].push(s[st].top());
            s[st].pop();
        } else if(op=="quit")
            return 0;
    }
}