#include <iostream>
#include <string>
using namespace std;

int main(){
    int N,H[20];
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>H[i];
    }

    int height=0;
    int number_buildings_can_see_sea=0;
    for(int i=0; i<N; i++){
        if(height<=H[i]){
            number_buildings_can_see_sea += 1;
            height=H[i];
        }
    }
    cout<<number_buildings_can_see_sea<<endl;
}