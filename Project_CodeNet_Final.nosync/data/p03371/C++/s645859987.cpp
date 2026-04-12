#include<iostream>
using namespace std;
#include<string>
#include<utility>
#include<algorithm>
#include<vector>

int main(){
    int  A,B,C;
    long long int X,Y;
    cin >> A >> B >> C;
    cin >> X >> Y;
    int num_x=0;
    int num_y=0;
    int num_dob=0;
    int res_pas=0;
    int res_end=0;
    int result_ini=A*X+Y*B;
    int res_dob_max=0;
    int dob=A+B;
        if(X>Y){
            res_pas=2*C*Y;
            res_dob_max=2*C*X;
            if(A<=2*C){
                res_pas+=A*(X-Y);
            }
            else{
                res_pas+=2*C*(X-Y);
            }
        }
        else{
            res_pas=2*C*X;
            res_dob_max=2*C*Y;
            if(B<=2*C){
                res_pas+=B*(Y-X);
            }
            else{
                res_pas+=2*C*(Y-X);
            }
        }
    if(res_pas>0){
    if(result_ini>=res_pas){
        result_ini=res_pas;
    }
}
    if(res_dob_max>0){
    if(result_ini>=res_dob_max){
        result_ini=res_dob_max;
    }
}
    res_end=result_ini;
    cout << res_end <<endl;
}