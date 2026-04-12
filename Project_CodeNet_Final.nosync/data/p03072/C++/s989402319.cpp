#include<iostream>
#include<algorithm>

using namespace std;
int main(){
int N;
cin >> N;
int H[N];
for(int i=0;i<N;i++)cin >> H[i];
int Sea=1,see=0;
for(int l=1;l<N;l++){
see=1;
for(int i=0;i<l;i++){
if(H[i]>H[l]){
see=0;
break;
}
}
Sea+=see;
}
cout << Sea << endl;

 return 0;
}
