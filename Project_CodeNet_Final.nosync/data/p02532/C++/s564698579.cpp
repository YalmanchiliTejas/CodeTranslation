#include<iostream>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
int main(){
    char a[5];
    stack<char>S[100];
    queue<char>Q;
    int m;
    cin>>m;
    while(cin>>a,strcmp(a,"quit")){
        if(!strcmp(a,"push")){
            int n;
            char c;
            cin>>n>>c;
            S[n-1].push(c);
        }else if(!strcmp(a,"pop")){
            int n;
            cin>>n;
            Q.push(S[n-1].top());
            S[n-1].pop();
        }else{
            int p1,p2;
            cin>>p1>>p2;
            S[p2-1].push(S[p1-1].top());
            S[p1-1].pop();
        }
    }
    while(Q.size()){
        cout<<Q.front()<<endl;
        Q.pop();
    }
    return 0;
}