#include<iostream>

using namespace std;

int main(){
    int l , j = 0,h[20],n,count = 1;
    bool view = false;
    cin >> n;
    while(cin>>l){
        h[j] = l;
        j++;
    }

    for(int i = 1;i< n;i++){
        for(int k = (i-1);k >= 0 ;k--){
            if(h[i] < h[k]){
                view = false;break;
            }else{
                view = true;
            }
        }
        if(view == true)count++;
    }
    printf("%d",count);
    return 0;
}