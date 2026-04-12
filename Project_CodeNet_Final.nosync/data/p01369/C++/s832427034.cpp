#include <iostream> // C++の入出力
#include <stdio.h> // C の入出力
#include <algorithm> // sort などのアルゴリズム
#include <string.h> // C の文字列用
#include <ctype.h> // C の文字種用
#include <string> // C++の文字列
#include <math.h>
using namespace std;
int main(void){
    string in;
    string left="qwertasdfgzxcvb";
    string right="yuiophjklnm";
    while(true){
        cin>>in;
        if(in=="#")break;
        bool sw=1;//leftなら1、rightなら0
        for(int i=0;i<right.length();i++){
            if(in[0]==right[i]){
                sw=0;
                break;
            }
        }
        int cnt=0;
        for(int s=1;s<in.length();s++){
            bool kensa=0;
            for(int i=0;i<left.length();i++){
                if(in[s]==left[i]){
                    if(sw==0){
                        cnt++;
                    }
                    kensa=1;
                    sw=1;
                    break;
                }
            }
            if(kensa==1){
                continue;
            }else{
                for(int i=0;i<right.length();i++){
                    if(in[s]==right[i]){
                        if(sw==1){
                            cnt++;
                        }
                        sw=0;
                        break;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}