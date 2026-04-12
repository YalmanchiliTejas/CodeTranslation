#include <iostream>
using namespace std;

int main(void){
    int n=0;
    int h[100]={0};
    int num=0;
    int flag=0;

    cin >> n;

    for(int count=0;count<n;count++){
        cin >> h[count];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(h[j]<=h[i]){
                flag=1;
            }else{
                flag=0;
                break;
            }
        }
        if(flag==1)num++;
    }

    cout << num << endl;

    return 0;
}