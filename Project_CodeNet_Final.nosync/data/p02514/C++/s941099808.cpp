#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <stdio.h>
using namespace std;

struct BOT{
	int x0, x1, y0, y1;
	string name;
	int saki;
};

struct PAGE{
	string name;
	vector<struct BOT> botan;
};

int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		int W, H;
		cin>>W>>H;
		vector<struct PAGE> page;
		for(int i=0; i<n; i++){
			string temp;
			cin>>temp;
			int m;
			cin>>m;
			struct PAGE tp;
			tp.name = temp;
			for(int j=0; j<m; j++){
				int x0, x1, y0, y1;
				cin>>x0>>y0;
				cin>>x1>>y1;
				struct BOT tb;
				tb.x0 = x0;
				tb.y0 = y0;
				tb.x1 = x1;
				tb.y1 = y1;
				string link;
				cin>>link;
				tb.name = link;
				tp.botan.push_back(tb);
			}
			page.push_back(tp);
		}
		for(int i=0; i<page.size(); i++){
			for(int j=0; j<page[i].botan.size(); j++){
				for(int k=0; k<page.size(); k++){
					//cout<<"aaaa"<<page[k].name;
					if(page[i].botan[j].name==page[k].name){
						page[i].botan[j].saki = k;
						break;
					}
				}
			}
		}
		/*

		for(int i=0; i<page.size(); i++){
			cout<<"page"<<page[i].name<<endl;
			cout<<"bottan";
			for(int j=0; j<page[i].botan.size(); j++){
				cout<<page[i].botan[j].saki<<" ";
			}
			cout<<endl;
		}*/







		int m;
		cin>>m;
		vector<int> hensen;
		for(int i=0; i<m+5; i++){
			hensen.push_back(-1);
		}
		hensen[0] = 0;
		int now = 0;
		for(int i=0; i<m; i++){
			string act;
			cin>>act;
			if(act=="click"){
				int x, y;
				cin>>x>>y;
				for(int j=0; j<page[hensen[now]].botan.size(); j++){
					if(page[hensen[now]].botan[j].x0<=x && page[hensen[now]].botan[j].x1>=x
						&& page[hensen[now]].botan[j].y0<=y && page[hensen[now]].botan[j].y1>=y){
							hensen[now+1] = page[hensen[now]].botan[j].saki;
							hensen[now+2] = -1;
							now++;
							break;
					}
				}
			} else if(act=="show"){
				//cout<<"!!!";
				//for(int j=0; j<hensen.size();j++){
				//	cout<<hensen[j]<<" ";
				//}
				cout<<page[hensen[now]].name<<endl;
			} else if(act=="back"){
				now = max(0, now-1);
			} else if(act=="forward"){
				if(hensen[now+1]!=-1){
					now++;
				}
			}
		}







	}
	return 0;
}