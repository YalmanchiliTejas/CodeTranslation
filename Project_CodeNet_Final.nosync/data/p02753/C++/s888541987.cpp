#include<iostream>
#include <string>

#define all(x) (x).begin(),(x).end()
#define puts(x) cout<< x << endl;
#define REP(i,m,n) for(int i=m;i<n;i++)
#define fore(i,a) for(auto i:a)
using namespace std;

string s;
int main(){
    int a=0,b=0;
    cin>>s;
    fore(i,s){
        if(i=='A'){
            a++;
        }else{
            b++;
        }
    }
    if(a==0||b==0){
        puts("No");
    }else{
        puts("Yes");
    }
}