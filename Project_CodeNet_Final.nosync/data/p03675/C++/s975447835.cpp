#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int n,a[200000];
deque<int> deck;
bool rev=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        if(!rev){
            deck.push_back(a[i]);
            rev=1;
        }
        else{
            deck.push_front(a[i]);
            rev=0;
        }
    }
    if(!rev){
        printf("%d",deck.front());
        deck.pop_front();
        for(int i=1;i<n;i++){
            printf(" %d",deck.front());
            deck.pop_front();
        }
    }
    else{
        printf("%d",deck.back());
        deck.pop_back();
        for(int i=1;i<n;i++){
            printf(" %d",deck.back());
            deck.pop_back();
        }
    }
    puts("");
    return 0;
}