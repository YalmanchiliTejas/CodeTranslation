#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>//cout << fixed << setprecision() <<
#include <set>
#include <map>
using ll = long long;
using namespace std;

double Mcos(double k){return cos(k*atan(1.0)*4/180);}
double Msin(double k){return sin(k*atan(1.0)*4/180);}

int main(void){
    string s;
    cin>>s;
    if(s=="AAA" || s=="BBB")cout<<"No";
    else cout<<"Yes";
}
