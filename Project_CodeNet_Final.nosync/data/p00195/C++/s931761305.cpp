#include<iostream>
using namespace std;

int main(){
    while(1){
        int a,b,bm=0,s;
        for(int i=0;i<5;i++){
            cin >> a >> b;
            if(a==0&&b==0)goto end;
            if(bm<a+b){
                bm=a+b;
                s=i;
            }
        }
        if(s==0)cout << "A ";
        else if(s==1)cout << "B ";
        else if(s==2)cout << "C ";
        else if(s==3)cout << "D ";
        else if(s==4)cout << "E ";
        cout << bm << endl;
    }
        end:;
    return 0;
}