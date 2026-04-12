#include<iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
string a;
string::iterator itr;
int aa=0;
bool light;
int main(){
	while(cin>>a){
	itr=a.begin();
	if(*itr=='y'||*itr=='u'||*itr=='i'||*itr=='o'||*itr=='p'||*itr=='h'||*itr=='j'||*itr=='k'||*itr=='l'||*itr=='m'||*itr=='n'){
		light=true;}else
			if(*itr=='#'){break;}else{
		light=false;}
		a.erase(a.begin());
		while(a.size()!=0){
			itr=a.begin();
	if(*itr=='y'||*itr=='u'||*itr=='i'||*itr=='o'||*itr=='p'||*itr=='h'||*itr=='j'||*itr=='k'||*itr=='l'||*itr=='m'||*itr=='n'){
		if(light==false){
		aa++;}light=true;}else{
		if(light==true){
		aa++;}light=false;}
		a.erase(a.begin());}
	cout<<aa<<endl;
	aa=0;}
    return 0;}
