#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int price=0;
    
    c*=2;

    int buy[]={a,b,c};

    if(a>c && b>c){
        // printf("a");
        while(x>0 || y>0){
            price+=c;
            x--;
            y--;
        }
    }else if((a+b)>c){
        // printf("b");
        while(x>0 && y>0){
            price+=c;
            x--;
            y--;
        }
        if(a>c){
            while(x>0){
                price+=c;
                x--;
                y--;
            }
            while(y>0){
                price+=b;
                y--;
            }
        } else if(b>c){
            while(y>0){
                price+=c;
                x--;
                y--;
            }
            while(x>0){
                price+=a;
                x--;
            }
        }else{
            while(x>0){
                price+=a;
                x--;
            }
            while(y>0){
                price+=b;
                y--;
            }
        }
    } else if(a>c){
        // printf("c");
        while(x>0){
            price+=c;
            x--;
            y--;
        }
        while(y>0){
            price+=b;
            y--;
        }
    } else if(b>c){
        while(y>0){
            price+=c;
            x--;
            y--;
        }
        while(x>0){
            price+=a;
            x--;
        }
    } else {
        // printf("d");
        while(x>0){
            price+=a;
            x--;
        }
        while(y>0){
            price+=b;
            y--;
        }
    }

    cout<<price<<endl;
}