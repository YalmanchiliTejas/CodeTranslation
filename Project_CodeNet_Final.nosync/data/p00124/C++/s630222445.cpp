#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <fstream>
#include <sstream>
#include <math.h>
#include <queue>
#include <stack>
#include <math.h>


using namespace std;

struct country_point{
    string country;
    int num;
    int point;
};

bool country_point_compare(country_point l, country_point r){
    if(l.point>r.point)return true;
    if(l.point<r.point)return false;
    if(l.num<r.num)return true;
    return false;
}

int main(){
    int n;
    bool flag=false;
    while(cin>>n){
        if(n==0)break;
        if(flag)cout<<endl;
        flag = true;

        country_point all_country[10];
        for(int i=0; i<n; i++){
            string c;
            cin>>c;
            all_country[i].country = c;
            int win, loss, drow;
            cin>>win;
            all_country[i].point=win*3;
            cin>>loss;
            cin>>drow;
            all_country[i].point+=drow;
            all_country[i].num = i;
        }
        
        sort(all_country, all_country+n, country_point_compare);
        
        for(int i=0; i<n; i++){
            cout<<all_country[i].country<<","<<all_country[i].point<<endl;
        }
    }
    
}