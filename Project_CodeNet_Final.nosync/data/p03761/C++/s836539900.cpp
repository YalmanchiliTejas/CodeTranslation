#include<iostream>
#include<string.h>
#include<cstring>

using namespace std;


typedef struct{

}list_t;

int main(){

    int n;
    cin >> n;

    string str[n];
    for(int i=0;i<n;i++)cin >> str[i];

    int characters[26];
    for(int i=0;i<26;i++)characters[i] = 50;
    int tmp[26];

    for(int i=0;i<n;i++){
        int j;

        for(j=0;j<26;j++)tmp[j] = 0;

        j = 0;
        while(str[i][j]){
            for(int k=0;k<26;k++){
                if(str[i][j] == char(int('a')+k)){
                    tmp[k]++;
                    break;
                }
            }
            j++;
        }

        for(int j=0;j<26;j++){
            if(characters[j]>tmp[j])characters[j] = tmp[j];
        }
    }

    for(int j=0;j<26;j++){
        //cout << characters[j];
        for(int loop=0;loop<characters[j];loop++)cout << char(int('a')+j);
    }
    cout << endl;


    return 0;
}
