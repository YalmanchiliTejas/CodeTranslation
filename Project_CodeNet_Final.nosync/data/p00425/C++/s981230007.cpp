#include<iostream>
#include<string>

using namespace std;
    int si[6];

    int main(){
        while(1){
        int sum = 1;
        si[0]=1;
        si[1]=2;
        si[2]=3;
        si[3]=5;
        si[4]=4;
        si[5]=6;
        int H;
    int coun=0;
    cin >> coun ;
    if(coun == 0)break;
    string num;
    for(int a=0;a<coun;a++){
        cin >> num;
        if(num == "North"){
        H=si[0];
        si[0]=si[1];
        si[1]=si[5];
        si[5]=si[3];
        si[3]=H;
     //   cout << si[0];
        }else
        if(num == "East"){
        H=si[0];
        si[0]=si[4];
        si[4]=si[5];
        si[5]=si[2];
        si[2]=H;
      //          cout << si[0];
        }else
        if(num == "West"){
        H=si[0];
        si[0]=si[2];
        si[2]=si[5];
        si[5]=si[4];
        si[4]=H;
        //        cout << si[0];
        }else if(num == "South"){
        H=si[0];
        si[0]=si[3];
        si[3]=si[5];
        si[5]=si[1];
        si[1]=H;
          //      cout << si[0];
        }else if(num == "Right"){
        H=si[1];
        si[1]=si[2];
        si[2]=si[3];
        si[3]=si[4];
        si[4]=H;
            //    cout << si[0];
        }else if(num == "Left"){
        H=si[1];
        si[1]=si[4];
        si[4]=si[3];
        si[3]=si[2];
        si[2]=H;
              //  cout << si[0];
        }
        sum = sum + si[0];

    }
    cout << sum << endl;
        }
return 0;
}