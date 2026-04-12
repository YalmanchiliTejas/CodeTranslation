#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(ll i=(n);i<(k);i++)
ll n;
string s;
bool decideAnimal(ll i,vector<bool> animals);
void Main(){    
    cin>>n>>s;
    bool flag=false,flag1,flag2;
    vector<bool> animals(n);//True=Sheep,False=Wolf
    For(i,0,4){
        animals.at(0)=i%2;
        animals.at(1)=i/2;
        flag1=false;flag2=false;
        For(j,2,n){
            animals.at(j)=decideAnimal(j,animals);
        }
        /*For(j,0,n){
            if(animals.at(j)) cout<<'S';
            else cout<<'W';
        }
        cout<<endl;*/
        if(animals.at(n-1)){
            if(s.at(n-1)=='o'){
                if(animals.at(n-2)==animals.at(0)){
                    flag1=true;
                }
            }
            else{
                if(animals.at(n-2)!=animals.at(0)){
                    flag1=true;
                }             
            }
        }
        else{
            if(s.at(n-1)=='o'){
                if(animals.at(n-2)!=animals.at(0)){
                    flag1=true;
                }
            }
            else{
                if(animals.at(n-2)==animals.at(0)){
                    flag1=true;
                }           
            }
        }
        if(animals.at(0)){
            if(s.at(0)=='o'){
                if(animals.at(n-1)==animals.at(1)){
                    flag2=true;
                }
            }
            else{
                if(animals.at(n-1)!=animals.at(1)){
                    flag2=true;
                }             
            }
        }
        else{
            if(s.at(0)=='o'){
                if(animals.at(n-1)!=animals.at(1)){
                    flag2=true;
                }
            }
            else{
                if(animals.at(n-1)==animals.at(1)){
                    flag2=true;
                }           
            }
        }
        if(flag1&&flag2){
            flag=true;
            break;
        }
    }
    if(!flag){
        cout<<-1<<endl;
        return;
    }
    else{
        For(i,0,n){
            if(animals.at(i)) cout<<'S';
            else cout<<'W';
        }
        cout<<endl;
        return;
    }
}
bool decideAnimal(ll i,vector<bool> animals){
    if(animals.at(i-1)){
        if(s.at(i-1)=='o'){
            return animals.at(i-2);
        }
        else{
            return !animals.at(i-2);
        }
    }
    else{
        if(s.at(i-1)=='o'){
            return !animals.at(i-2);
        }
        else{
            return animals.at(i-2);
        }
    }
}
int main(){
    Main();
    return 0;
}