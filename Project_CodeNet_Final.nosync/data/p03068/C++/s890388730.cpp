#include <bits/stdc++.h>
using namespace std;

int main(){
 int N, M ;
string str;
cin >> N >> str >> M ;
for(int i = 0 ; i < N; i++){
 if(str.at(i) == str.at(M - 1) ){
cout << str.at(M - 1)  ;
} 
 else{
cout << "*"  ;
}
}
cout << endl;
}