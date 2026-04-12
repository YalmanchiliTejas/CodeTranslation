#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int h[n];
    for(int i=0;i<n;i++){
        cin >> h[i];//0~n-1
    }

    int goukei = 0;

    for(int i=0;i<n;i++){

        int max;
        max = h[0];

        if(i==0){
            goukei++;
        }
        else{
            for(int j=0;j<=i-1;j++){
                if(max<h[j]){
                    max = h[j];
                }
            }
            //cout << "max=" << max << " ";
            if(max<=h[i]){
                goukei++;
            }
        }
        //cout << goukei << " ";

    }

    cout << goukei << endl;


    return 0;
}