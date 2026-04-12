#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int box[26]={};
    char str[51];
    for(int i=0;i<num;i++){
        int current[26]={};
        cin >> str;
        for(int j=0;j<strlen(str);j++){
            current[(int)str[j]-97]++;
        }
        for(int j=0;j<26;j++){
            if(i==0){
                box[j]=current[j];
            }else{
                box[j]=min(box[j],current[j]);
            }
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<box[i];j++){
            cout << (char)(i+97);
        }
    }
    cout << endl;
    return 0;
}