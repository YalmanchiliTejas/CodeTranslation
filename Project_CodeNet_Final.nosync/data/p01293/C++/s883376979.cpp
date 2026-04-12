#include<iostream>
#include<vector>
using namespace std;
 
#define NUMS 4
#define NUMR 13
 
int tonum(char ch){
  if('2' <= ch && ch <= '9') return ch - '0';
  else switch(ch){
    case 'T': return 10;
    case 'J': return 11;
    case 'Q': return 12;
    case 'K': return 13;
    case 'A': return 14;
    case 'C': return 4;
    case 'D': return 3;
    case 'H': return 2;
    case 'S': return 1;
    }
 
  return -1;
}
signed main(){
 
  while(true){
    char Trump, temp;
    int NS = 0, EW = 0, now = 0;
    string card[NUMS][NUMR];
     
    cin>>Trump;
 
    if(Trump == '#') break;
 
    for(int i = 0; i < NUMS; i++){
      for(int j = 0; j < NUMR; j++){
    cin>>card[i][j];
      }
    }
 
    for(int i = 0; i < NUMR; i++){
      int maxS = -1, maxH = -1, maxD = -1, maxC = -1, maxT = -1, maxO = -1;
      int maxSj = -1, maxHj = -1, maxDj = -1, maxCj = -1, maxTj = -1, maxOj = -1;
      temp = card[now][i][1];
      // cout<<"i = "<<i<<" now "<<now<<" "<<temp<<endl;
      for(int j = 0; j < NUMS; j++){
 
    if(card[j][i][1] == Trump && maxT < tonum(card[j][i][0])) maxT = tonum(card[j][i][0]), maxTj = j;
    else if(card[j][i][1] != Trump && card[j][i][1] == temp && maxO < tonum(card[j][i][0])) maxO = tonum(card[j][i][0]), maxOj = j;
    //else if(card[j][i][1] != Trump && maxO < tonum(card[j][i][0])) maxO = tonum(card[j][i][0]), maxOj = j;
    //  else if(card[j][i][1] != Trump && maxO == tonum(card[j][i][0]) && tonum(card[maxOj][i][1]) < tonum(card[j][i][1]))  maxO = tonum(card[j][i][0]), maxOj = j;
    switch(card[j][i][1]){
    case 'S': if(maxS < tonum(card[j][i][0])) maxS = tonum(card[j][i][0]), maxSj = j; break;
    case 'H': if(maxH < tonum(card[j][i][0])) maxH = tonum(card[j][i][0]), maxHj = j; break;
    case 'D': if(maxD < tonum(card[j][i][0])) maxD = tonum(card[j][i][0]), maxDj = j; break;
    case 'C': if(maxC < tonum(card[j][i][0])) maxC = tonum(card[j][i][0]), maxCj = j; break;
 
    }
      }
 
      if(maxT != -1){
     
    //  cout<<"i = "<<i<<" maxTj "<<maxTj<<endl;
    if(maxTj == 0 || maxTj == 2) {
      NS++;
    } else {
      EW++;
      //  cout<<"WE i = "<<i<<endl;
    }
    now = maxTj;
      } else {
     
    //  cout<<"i = "<<i<<" maxOj "<<maxOj<<endl;
     
    if(maxOj == 0 || maxOj == 2) NS++;
    else {
      EW++;
      // cout<<"WE i = "<<i<<endl;
    }
    now = maxOj;
    /*
    if(maxCj == 0 || maxCj == 2){
      NS++;
    } else if(maxCj == 1 || maxCj == 3){
      EW++; cout<<"cWE i = "<<i<<" "<<maxC<<endl;
    } else  if(maxDj == 0 || maxDj == 2){
      NS++;
    } else if(maxDj == 1 || maxDj == 3){
      EW++; cout<<"dWE i = "<<i<<endl;
    } else  if(maxHj == 0 || maxHj == 2){
      NS++;
    } else if(maxHj == 1 || maxHj == 3){
      EW++; cout<<"hWE i = "<<i<<endl;
    } else  if(maxSj == 0 || maxSj == 2){
      NS++;
    } else if(maxSj == 1 || maxSj == 3){
      EW++; cout<<"sWE i = "<<i<<endl;
    }
    */
      }
    }
 
    cout<<((NS>EW)?"NS " + to_string(NS-6) : "EW " + to_string(EW-6))<<endl;
  }
 
  return 0;
}
