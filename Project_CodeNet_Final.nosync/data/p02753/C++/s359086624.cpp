#include<iostream>
using namespace std;
int main(){
string S;
cin>>S;
if(S=="ABA"||S=="BAB"||S=="AAB"||S=="BBA"||S=="ABB"||S=="BAA"){
    cout<<"Yes";
}
else cout<<"No";

return 0;
}
