#include <iostream>
using namespace std;
int main(void)
{
    int N,A,B,C,X;
    int Y[101];
    while(cin>>N>>A>>B>>C>>X){
        if(!(N||A||B||C||X)) break;
        for(int i=0; i<N; i++){
            cin >> Y[i];
        }
        int flame=0;
        int rel=0;
        while(flame<10001){
            if(X==Y[rel]) rel++;
            if(rel==N) break;
            flame++;
            X = (A*X+B)%C;
        }
        if(flame<10001){
            cout<<flame<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }
             
    return 0;
}
