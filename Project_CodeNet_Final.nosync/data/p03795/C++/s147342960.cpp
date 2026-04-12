#include <bits/stdc++.h>
using namespace std;
int main(void){

int a;
cin>>a;
int b=a*800;

if(a==15||a>15){
    cout<<b-((a/15)*200)<<endl;
}

else{
    cout<<b<<endl;
}
}
