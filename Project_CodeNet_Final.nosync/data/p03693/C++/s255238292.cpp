#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int result=a*100+b*10+c;
    if(result%4==0){
      cout<<"YES";
    }
    else cout<<"NO";
    return 0;
}