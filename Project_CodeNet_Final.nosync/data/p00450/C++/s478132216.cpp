#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class set{
public:
    bool white;
    int length;
    set(bool w,int l):white(w),length(l){}
    set(bool w):white(w),length(1){}
};
int main(){
    int time;
    while(cin>>time&&time){
        vector<set> line;
        for(int i=0;i<time;++i){
            int color;
            cin>>color;
            if(i%2==0){
                if(line.empty()){
                    line.push_back(set(color==0));
                }else{
                    if((color==0)==line.back().white){
                        ++line.back().length;
                    }else{
                        line.push_back(set(color==0));
                    }
                }
            }else{
                if((color==0)==line.back().white){
                    ++line.back().length;
                }else{
                    int num = line.back().length+1;
                    line.pop_back();
                    if(line.empty()){
                        line.push_back(set(color==0,num));
                    }else{
                        line.back().length+=num;
                    }
                }
            }
        }
        int num = 0;
        for(int i=0;i<line.size();++i){
            if(line[i].white){
                num+=line[i].length;
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
