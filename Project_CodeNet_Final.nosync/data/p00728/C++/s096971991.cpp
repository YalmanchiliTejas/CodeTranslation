#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while(1){

        int sum=0,avg=0;
     
        cin>>n;

        if( n == 0) break;

        vector<int>  point(n);

        for(int i=0; i<n; i++){

            cin>>point.at(i);
        }

        sort(point.begin(),point.end());



        for(int i = 0; i<n; i++){

         sum += point.at(i);

        }
        
        avg = (sum - point.at(0) - point.at(n-1) ) / (n -2);

        cout<<avg<<endl;
    }


    return 0;

}
