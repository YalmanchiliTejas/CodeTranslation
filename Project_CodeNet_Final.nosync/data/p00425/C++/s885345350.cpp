#include<iostream>
#include<string>

using namespace std;
int main(){
    int n,sum=1,num,here=1,up=5,down=2,right=3,left=4;
    string str;

    while(1){
    cin >> n;
    if(n==0)break;
    for(int i=0;i<n;i++){
        cin >> str;
        if(str=="North"){
            num=down;
            down=7-here;
            up=here;
            here=num;
            sum=here+sum;

        }else
        if(str=="South"){
            num=up;
            up=7-here;
            down=here;
            here=num;
            sum=here+sum;


        }else
        if(str=="East"){
            num=left;
            left=7-here;
            right=here;
            here=num;
            sum=here+sum;

        }else
        if(str=="West"){
            num=right;
            right=7-here;
            left=here;
            here=num;
            sum=here+sum;

        }else
        if(str=="Left"){
            num=down;
            down=left;
            left=up;
            up=right;
            right=num;
            sum=here+sum;


        }else
        if(str=="Right"){
            num=down;
            down=right;
            right=up;
            up=left;
            left=num;
            sum=here+sum;


        }
    }

    cout << sum << endl;
    sum=1;
    here=1;
    right=3;
    left=4;
    up=5;
    down=2;
    }
return 0;
}