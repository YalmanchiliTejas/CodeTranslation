//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2709
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<array>

using namespace std;

int log(int base, int n, int count)
{
    return n == 0 ? count : log(base, (n - 1) / base, count + 1);
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    map<int, int> toDR{};

    vector<int> d(0);
    for(int i = 0; i < M; i++)
    {
        int tmp{ 0 };
        cin >> tmp;
        d.push_back(tmp);
        toDR.insert(make_pair(tmp, i));
    }

    vector< vector<int> > v{};
    for(int i = 0; i < N; i++)
    {
        vector<int> tmp_v{};
        for(int j = 0; j < K; j++)
        {
            int tmp{ 0 };
            cin >> tmp;
            tmp_v.push_back(tmp);
        }
        v.push_back(tmp_v);
    }

    //???????????????????????????????????????
    //?????§??????????????? ?????§????????????

    queue<int> que{};

    //?????????????????¨??????????????¨?±??????????
    //?????????
    que.push((1 << M) - 1);

    array<int, 1 << 16 > come;
    come.fill(-1);
    come[que.front()] = 0;

//    int loopCount = 0;
    while(que.front() != 0)
    {

        int dr = que.front();

        for(int i = 0; i < K; i++)
        {
            //loopCount++;

            int nextState = 0;
            for(int j = 0; j < M; j++)
            {
                if( dr & (1 << j) )
                {
                    if(toDR.count(v[d[j] - 1][i]) == 0)continue;

                    //v[d[j]][i]????§????
                    nextState |= (1 << (toDR[v[d[j] - 1][i]]) );
                }

            }

            if(nextState == 0)
            {
                //?????????
          //      for(int i = 0; i < 10; i++)
        //            cout << come[i] << " ";

                cout << come[dr] + 1 << endl;
                return 0;
            }

            //que?????????
            if(come[nextState] == -1)
            {
                que.push(nextState);
                come[nextState] = come[dr] + 1;
            }
        }
        que.pop();
    }

    return 0;
}