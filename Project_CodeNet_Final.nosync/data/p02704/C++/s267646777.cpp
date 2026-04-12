#define _GLIBCXX_DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <cstring>
#include <numeric>
#include <cassert>
using namespace std;

template <class T>
bool chmin(T &x,T y)
{
    if(x>y)
    {
        x=y;
        return true;
    }
    return false;
}

void fail()
{
    cout << -1 << "\n";
    exit(0);
}

using u64=uint64_t;

main()
{
    int n; cin>>n;
    vector ans(n,vector<u64>(n,0));

    // input
    vector<u64> s(n),t(n),u(n),v(n);
    for(u64 &e: s) cin>>e;
    for(u64 &e: t) cin>>e;
    for(u64 &e: u) cin>>e;
    for(u64 &e: v) cin>>e;


    for(int b=0; b<64; ++b)
    {
        int tmp[555][555];
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                tmp[i][j]=-1;
            }
        }

        vector<int> rex[2],cex[2];
        vector<int> ry,cy;
        bool rf[2]={};
        bool cf[2]={};

        // row
        for(int r=0; r<n; ++r)
        {
            u64 now=(u[r]>>b)&1ull;
            if(s[r]==now) // existence of (now)
            {
                rex[now].emplace_back(r);
                ry.emplace_back(r);
            }
            else // all now
            {
                rf[now]=true;
                for(int c=0; c<n; ++c) tmp[r][c]=now;
            }
        }

        // column
        for(int c=0; c<n; ++c)
        {
            u64 now=(v[c]>>b)&1ull;
            if(t[c]==now) // existence of (now)
            {
                cex[now].emplace_back(c);
                cy.emplace_back(c);
            }
            else // all now
            {
                cf[now]=true;
                for(int r=0; r<n; ++r)
                {
                    if(~tmp[r][c] and tmp[r][c]!=now) fail();
                    tmp[r][c]=now;
                }
            }
        }

        int ryet=ry.size();
        int cyet=cy.size();
        if(min(ryet, cyet)>1) // checker board
        {
            for(int i=0; i<ryet; ++i)
            {
                for(int j=0; j<cyet; ++j)
                {
                    bool flag=(i+j)&1;
                    tmp[ry[i]][cy[j]]=flag;
                }
            }
        }
        else
        {
            if(!ryet)
            {
                for(bool t: {0,1})
                {
                    for(int c: cex[t])
                    {
                        bool ok=false;
                        for(int r=0; r<n; ++r)
                        {
                            if(t==tmp[r][c]) ok=true;
                        }
                        if(!ok) fail();
                    }
                }
            }
            else if(!cyet)
            {
                for(bool t: {0,1})
                {
                    for(int r: rex[t])
                    {
                        bool ok=false;
                        for(int c=0; c<n; ++c)
                        {
                            if(t==tmp[r][c]) ok=true;
                        }
                        if(!ok) fail();
                    }
                }
            }
            else // ryet>0 and cyet>0
            {
                if(ryet==1)
                {
                    const int ur=ry.front();
                    int targ=rex[0].empty();
                    auto &urow=tmp[ry.front()];
                    bool ok=false;
                    for(bool t: {0,1})
                    {
                        if(rf[t]) continue;
                        for(int c: cex[t])
                        {
                            urow[c]=t;
                            if(t==targ) ok=true;
                        }
                    }
                    for(int c=0; c<n; ++c)
                    {
                        if(urow[c]<0)
                        {
                            ok=true;
                            urow[c]=targ;
                        }
                    }
                    ok|=cf[targ];
                    if(!ok) fail();
                }
                else // cyet==1
                {
                    const int uc=cy.front();
                    int targ=cex[0].empty();
                    bool ok=false;
                    for(bool t: {0,1})
                    {
                        if(cf[t]) continue;
                        for(int r: rex[t])
                        {
                            tmp[r][uc]=t;
                            if(t==targ) ok=true;
                        }
                    }
                    for(int r=0; r<n; ++r)
                    {
                        if(tmp[r][uc]<0)
                        {
                            ok=true;
                            tmp[r][uc]=targ;
                        }
                    }
                    ok|=rf[targ];
                    if(!ok) fail();
                }
            }
        }

        // update ans
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                assert(~tmp[i][j]);
                ans[i][j]|=u64(tmp[i][j])<<b;
            }
        }
    }

    // output
    for(auto &r : ans)
    {
        for(auto &e: r)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
}