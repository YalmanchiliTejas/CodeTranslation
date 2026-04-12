#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
int h,w;

bool allDots(int i){
    for(int k=0; k<grid[i].size(); k++)
        if(grid[i][k] != '.')
            return false;
    return true;
}
bool allDots2(int i){
    for(int k=0; k<grid.size(); k++)
        if(grid[k][i] != '.')
            return false;
    return true;
}

void printGrid(){
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    cin>>h>>w;

    for(int i=0; i<h; i++){
        grid.push_back(vector<char>());
        for(int j=0; j<w; j++){
            char c;
            cin>>c; grid[i].push_back(c);
        }
    }
    bool stop = false;
    while(!stop){
        //cout<<allDots(0)<<endl;
        //cout<<"here!\n";
        stop = true;
        //rows
        for(int i=0; i<grid.size(); i++){
            //cout<<"row: "<<i<<" dots: "<<allDots(i)<<endl;
            if(allDots(i)){
                stop = false;
                vector<vector<char>> newG;
                for(int k=0; k<grid.size(); k++){
                    if(k == i) continue;
                    newG.push_back(vector<char>());
                    for(int l=0; l<grid[k].size(); l++){
                        newG[newG.size()-1].push_back(grid[k][l]);
                    }
                }
                grid = newG;
                /*cout<<"row: "<<i<<endl; //printGrid();
                for(int n=0; n<newG.size(); n++){
                    for(int j=0; j<newG[n].size(); j++){
                        cout<<newG[n][j];
                    }
                    cout<<endl;
                }*/
            }
        }

        //cols
        for(int i=0; i<grid[0].size(); i++){
                //cout<<"col: "<<i<<" dots: "<<allDots2(i)<<endl;
            if(allDots2(i)){
                stop = false;
                vector<vector<char>> newG;
                for(int k=0; k<grid.size(); k++){
                    newG.push_back(vector<char>());
                    for(int l=0; l<grid[0].size(); l++){
                        if(l == i) continue;
                        newG[newG.size()-1].push_back(grid[k][l]);
                    }
                }
                grid = newG;
                /*cout<<"col: "<<i<<endl; //printGrid();
                for(int n=0; n<newG.size(); n++){
                    for(int j=0; j<newG[n].size(); j++){
                        cout<<newG[n][j];
                    }
                    cout<<endl;
                }*/
            }
        }
    }

    printGrid();

    return 0;
}
