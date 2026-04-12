#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using P = pair<int,char>;
using T = tuple<int,int,int>;

int main(){
    char trump;
    while(cin>>trump,trump!='#'){
        vector<P> V[4];
        for(int i=0;i<4;i++){
            for(int j=0;j<13;j++){
                char a,b;
                cin>>a>>b;
                int str;
                if('2'<=a&&a<='9'){
                    str=a-'2';
                }else if(a=='T'){
                    str=8;
                }else if(a=='J'){
                    str=9;
                }else if(a=='Q'){
                    str=10;
                }else if(a=='K'){
                    str=11;
                }else{
                    str=12;
                }
                V[i].emplace_back(str,b);
            }
        }
        int EW=0,NS=0;
        int leader=0;
        for(int i=0;i<13;i++){
            vector<T> Trick;
            for(int j=0;j<4;j++){
                int suit;
                if(get<1>(V[j][i])==trump){
                    suit=2;
                }else if(get<1>(V[j][i])==get<1>(V[leader][i])){
                    suit=1;
                }else{
                    suit=0;
                }
                int str=get<0>(V[j][i]);
                Trick.emplace_back(suit,str,j);   
            }
            sort(Trick.begin(), Trick.end(),greater<T>());
            leader=get<2>(Trick.front());
            if(leader%2){
                EW++;
            }else{
                NS++;
            }
        }
        if(NS>6){
            cout<<"NS "<<NS-6<<endl;
        }else{
            cout<<"EW "<<EW-6<<endl;
        }
    }

    return 0;
}