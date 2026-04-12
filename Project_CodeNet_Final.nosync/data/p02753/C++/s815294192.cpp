#include<bits/stdc++.h>
using namespace std;

int main(){
string S;
cin >> S;
bool a=true;
for(int i=0;i<2;i++){
if(S[i] != S[i+1]){a=false;}
}

if(!a){
cout << "Yes" << endl;
}else{
cout << "No" << endl;
}

}