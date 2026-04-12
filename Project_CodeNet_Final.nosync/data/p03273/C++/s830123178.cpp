#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int num_row, num_col,i,j,count=0;
    bool is=false;
    string input;
    string tmp,tmp2;
    vector<string> matrix;
    vector<string> tmp_matrix;
    vector<string> out_matrix;
    //vector<string> row;

    //take inputs
    cin>>num_row>>num_col;
    for(i=0; i<num_row; i++)
    {
        cin>>input;
        //row.push_back(input);

        matrix.push_back(input);
    }

    count =0;
    //remove column
    for(i=0; i<num_col; i++)
    {
        for(j=0; j<num_row; j++)
        {
            //cout<<"tmpppp "<<tmp<<endl;

            tmp = matrix[j][i];
            if(tmp == ".")
            {
                count++;
                //cout<<"heeeere"<<endl;
            }
        }
        //cout<<"count "<<count<<endl;
        //cout<<"num_row "<<num_row<<endl;
        if(count == num_row)
        {
            is=true;
    //            //cout<<"i "<<i<<endl;
            for(j=0; j<num_row;j++)
            {
                tmp2= matrix.at(j);
                //cout<<"tmp2 "<<tmp2<<endl;
                tmp2.erase(tmp2.begin()+i);
                //cout<<"tmp2 erased "<<tmp2<<endl;

                out_matrix.push_back(tmp2);
                //tmp.erase(matrix[j].begin()+i);
            }
            matrix.clear();
            for(j=0; j<num_row;j++)
            {
                matrix.push_back(out_matrix[j]);
            }
            out_matrix.clear();

            num_col--;
            i--;
        }
        count =0;
    }

        for(j=0; j<num_row; j++)
        {
            out_matrix.push_back(matrix[j]);
        }

    //remove row
    for(i=0; i<num_row; i++)
    {
        count=0;
        tmp = out_matrix[i];
        for(j=0; j<num_col; j++)
        {
            if(tmp[j] == '.')
                count++;
            else
                break;
        }
        if(count == num_col)
        {
            out_matrix.erase(out_matrix.begin()+i);
            num_row--;
            i--;
        }
    }

    //print outputs
    for(i=0; i<num_row; i++)
    {
        for(j=0; j<num_col; j++)
        {
            cout<<out_matrix[i][j];
        }
        cout<<endl;
    }

    return 0;
}
