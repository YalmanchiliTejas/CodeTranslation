#include<iostream>
#include<algorithm>

using namespace std;

#define REP(s,e) for(int i=(s);i<(e);i++)

int main(){
    int A;
    cin>>A;
    
    int c=A/15;
    
    cout<<A*800-c*200<<endl;
}
