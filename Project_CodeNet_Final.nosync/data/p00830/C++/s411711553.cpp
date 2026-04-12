#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct Node{
    string name;
    map<string,Node*> msn;
    Node *par;
    int num;
    Node(){
        par=NULL;
        num=0;
    }
};

int idx;

void parse(string s,Node *node){
    string name;
    string left;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='/'){
            name=s.substr(0,i);
            left=s.substr(i+1);
            break;
        }
        else if(i==s.size()-1){
            name=s;
            break;
        }
    }
    if(node->msn.find(name)==node->msn.end()){
        Node *nd = new Node();
        nd->name=name;
        nd->par=node;
        node->msn[name]=nd;
        // t@CÉÍidðÂ¯Ä¯Ê
        if(left=="")
            nd->num=idx++;
    }
    // Ü¾¶ªcÁÄ¢êÎAÄA
    if(left!="")
        parse(left,node->msn[name]);
}

// ßêéæ¤Éem[hÖÌQÆàÁÄ¨­
int search(Node *node,string path){
    if(node==NULL)return 0;
    // t@CÌêÜÅB
    if(node->num!=0)
        return node->num;
    // ±±ÅpXªóÉÈÁ½
    if(path==""){
        // indexªºÉ é©Å»f
        if(node->msn.find("index.html")==node->msn.end())
            return 0;
        return node->msn["index.html"]->num;
    }
    string name;
    string left;
    bool isFile=false;
    for(int i = 0; i < path.size(); i++){
        if(path[i]=='/'){
            name=path.substr(0,i);
            left=path.substr(i+1);
            break;
        }
        else if(i==path.size()-1){
            isFile=true;
            name=path;
            break;
        }
    }
    if(!isFile&&node->msn.find(name)!=node->msn.end()&&node->msn[name]->num!=0)
        return 0;
    // ÅºwÌfBNg é¢Ít@Cð¦·
    if(name=="..")
        return search(node->par,left);
    else if(name==".")
        return search(node,left);
    // ÄA
    if(node->msn.find(name)==node->msn.end())
        return 0;
    return search(node->msn[name],left);
}

void deleteTree(Node *node){
    if(node->msn.size()==0){
        delete node;
        return;
    }
    for(map<string,Node*>::iterator it=node->msn.begin();it!=node->msn.end();it++){
        deleteTree(node->msn[it->first]);
    }
}

int main(){

    int n,m;
    while(cin>>n>>m&&!(n==0&&m==0)){
        idx=1;
        Node *root = new Node();
        root->name+='/';
        root->par=NULL;
        for(int i = 0; i < n; i++){
            string s;
            cin>>s;
            parse(s.substr(1),root);
        }
        for(int i = 0; i < m; i++){
            string s1,s2;
            cin>>s1>>s2;
            int res1=search(root,s1.substr(1));
            int res2=search(root,s2.substr(1));
            if(res1==0||res2==0)cout<<"not found"<<endl;
            else if(res1==res2)cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
        deleteTree(root);
    }

    return 0;
}