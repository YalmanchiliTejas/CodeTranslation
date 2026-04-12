#include<iostream>
using namespace std;
int main()
{
    char arr[100][100];
    int r,c;
    int count1=0,count2=0;
    cin>>r>>c;
    for(int i=0 ; i<r ; i++){
        for(int j=0 ; j<c ; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0 ; i<r ; i++){
            if(arr[i][0] == '.'){
                for(int j=1 ; j<c ; j++){
                    if(arr[i][j] == '.'){
                        count1++;
                    }
                }
                if(count1 == c-1){
                    arr[i][0] = 'a';
                    for(int j=1 ; j<c ; j++){
                    arr[i][j] = 'a';
                }
                }
           }
           count1 = 0;
    }
    for(int i=0 ; i<c ; i++){
            if(arr[0][i] == '.' ||arr[0][i] == 'a'){
                for(int j=1 ; j<r ; j++){
                    if(arr[j][i] == '.' || arr[j][i] == 'a'){
                        count2++;
                    }
                }
                if(count2 == r-1){
                    arr[0][i] = 'a';
                    for(int j=1 ; j<r ; j++){
                    arr[j][i] = 'a';
                }
                }
           }
           count2 = 0;
    }
    int c3=0;
    for(int i=0 ; i<r ; i++){
        for(int j=0 ; j<c ; j++){
                if(arr[i][j] == 'a'){
                    c3++;
                }
                if(arr[i][j]!= 'a'){
                cout<<arr[i][j];
                }
        }
        if(c3 == c){
            c3 = 0;
        }
        else if(i < r-1){
            cout<<endl;
            c3 = 0;
        }
    }
    return 0;
}
