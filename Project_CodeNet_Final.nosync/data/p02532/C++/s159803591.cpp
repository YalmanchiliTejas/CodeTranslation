#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<string>q[101];
    string s;
    int i,j;
    cin>>i;
    while(cin>>s){
        if(s=="quit")break;
        if(s=="push"){
            cin>>i>>s;
            q[i].push(s);
        } else if(s=="move"){
            cin>>i>>j;
            q[j].push(q[i].top());
            q[i].pop();
        } else {
            cin>>i;
            cout<<q[i].top()<<endl;
            q[i].pop();
        }
    }
}