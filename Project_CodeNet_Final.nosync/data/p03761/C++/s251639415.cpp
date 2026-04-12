#include<iostream>
#include<string>
using namespace std;
int main()
{
    int Z=0;
    //-----------

    string strs[50];
    int n;

    int tmpcount[26]={0};
    int count[26]={0};
    int init = 0;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>strs[i];
    }

    //文字列のなかで最小の文字が含まれる文字列の文字数を探す（意味不明）



    for(int i=0;i<n;i++)
    {
        //文字の全探索
        for(int j=0;j<strs[i].size();j++)
        {
            //デバッグ
            //cout<< (int)strs[i][j]-97 <<"=";
            //cout<<strs[i][j]<<endl;

            //文字数をカウント
            tmpcount[(int)strs[i][j]-97] ++;

        }
        //カウントを更新

        if(init == 0){
            for(int j=0;j<26;j++)
            {
                count[j] = tmpcount[j];//初回は全部コピー
            }
            init = 1;
        }
        else 
        {
             for(int j=0;j<26;j++)
            {
                if(count[j]!=tmpcount[j])
                count[j] = min(count[j],tmpcount[j]);//小さい方を代入

            }
        }

        //tmpの初期化
        for(int j=0;j<26;j++)
            {
               
                tmpcount[j] = 0;

            }


    }

    //出力

    for(int i=0;i<26;i++)
    {
        if(count[i]>0)
        {
            for(int j=0;j<count[i];j++)
            {
                cout<<(char)(97+i);
            }
        }
    }

    cout<<endl;

    //------------
    cin>>Z;//何と入力がなければ消さなくてもいいらしい

    return 0;
}