#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    int m,n;
    string in;
    for(;;){
        cin>>m>>n;
        if(m==0&&n==0) break;
        vector<bool> islive(m,true);
        int nokori=m,at=0;
        for(int ix=1;ix<=n;ix++){
            cin>>in;
            for(;at<m;at++){
                if(islive[at]) break;
            }
            if(at==m){
                for(at=0;at<m;at++){
                    if(islive[at]) break;
                }
            }
            if(nokori>1){
                bool is=false;
                if(ix%3==0&&ix%5==0){
                    if(in!=string("FizzBuzz")) is=true;
                }else if(ix%3==0){
                    if(in!=string("Fizz")) is=true;
                }else if(ix%5==0){
                    if(in!=string("Buzz")) is=true;
                }else{
                    stringstream ss;
                    ss<<ix;
                    if(in!=ss.str()){
                        is=true;
                    }
                }
                if(is){
                    nokori--;
                    islive[at]=false;
                }
                at++;
            }
        }
        vector<int> out;
        for(int i=0;i<m;i++){
            if(islive[i]) out.push_back(i+1);
        }
        cout<<out[0];
        for(int i=1;i<out.size();i++){
            cout<<" "<<out[i];
        }
        cout<<endl;
    }
}