#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string S[n];
    for(int i=0; i<n; i++){
        cin >> S[i];
    }

    int A;
    A= (int) 'z' - 'a' + 1;
    int list[A]={0};

    for(int i=0; i<n; i++){
        int list_tmp[A]={0};
        for(int j=0; j<S[i].size(); j++){
            list_tmp[ (int) S[i][j] - 'a' ]+=1;
        }
        if( i==0 ){
            for(int k=0; k<A; k++){
                list[k]=list_tmp[k];
            }
        }else{
            for(int k=0; k<A; k++){
                if( list[k]>list_tmp[k] ){
                    list[k]=list_tmp[k];
                }
            }
        }
    }

    for(int i=0; i<A; i++){
        for(int j=0; j<list[i]; j++){
            cout << (char) ( (int) 'a' + i );
        }
    }
    cout << endl;

    return 0;
}