#include <iostream>
    #include <stdio.h>
    #include <math.h>
    #include <string.h>
    #include <set>
    #define maxn 300008
    #define inf 200000000
    using namespace std;
    int minn[maxn << 2],add[maxn << 2];
    set<int> L,R;
    int sum[maxn];
    int n,q;
    int ans;
    struct kh
    {
        char c;
    }s[maxn];
    void pushdown(int i,int l,int r)
    {
        if(add[i]!=0)
        {
            int mid = (l+r)>>1;
            add[i<<1] += add[i];
            minn[i<<1] += add[i];
            add[i<<1|1] += add[i];
            minn[i<<1|1] += add[i];
            add[i]= 0;
        }
        return;
    }
    void update(int i,int l,int r,int ql,int qr,int val)
    {
    if(l > qr || ql > r)
        return;
        if(l>=ql&&r <= qr)
        {
            minn[i]+=val;
            add[i]+=val;
            return;
        }
        pushdown(i,l,r);
        int mid = (l+r)>>1;
        update(i<<1,l,mid,ql,qr,val);
        update(i<<1|1,mid+1,r,ql,qr,val);
        minn[i]=min(minn[i<<1],minn[i<<1|1]);
    }
    int que(int i,int l,int r,int ql,int qr)
    {
        if(l>qr||r<ql)
            {
                return inf;
            }
            if(l>=ql&&r <= qr)
            {
                return minn[i];
            }
            pushdown(i,l,r);
            int mid = (l + r)>> 1;
            return min(que(i<<1,l,mid,ql,qr),que(i<<1|1,mid+1,r,ql,qr));
    }
    void ef(int from,int to,int flag)   
    {
        if(from >= to)
        {
            ans =*(L.lower_bound(from));
            return;
        }
        int mid = (from+to)>>1;
        //cout << mid << endl;
        if(que(1,1,n,mid,flag)>=2)
        {
            ef(from,mid,flag);
        }
        else
        {
            ef(mid+1,to,flag);
        }
    }
    void flip(int res)
    {
        if(s[res].c==')')
        {
            s[res].c = '(';
            R.erase(res);
            L.insert(res);
            update(1,1,n,res,n,2);
        }
        else
        {
            s[res].c = ')';
            R.insert(res);
            L.erase(res);
            update(1,1,n,res,n,-2);
        }
    }
    int main()
    {
       // freopen("in.txt","r",stdin);
        sum[0] = 0;
        scanf("%d%d\n",&n,&q);
        for(int i = 1;i <= n;i ++)
        {
            //cout << "firstb:" <<  firstb << endl;
            scanf("%c",&s[i].c);
            
            if(s[i].c=='(')
            {
                L.insert(i);
            }
            else
            {
                R.insert(i);
            }
            if(s[i].c==')')
            {
                sum[i] = sum[i-1]-1;
            }
            else
            {
                sum[i] = sum[i-1]+1;
            }
            update(1,1,n,i,i,sum[i]);
        }
        while(q--)
        {
            //cout << "fb:" << *R.begin() << endl;
            int qu;
            scanf("%d",&qu);
            if(s[qu].c=='(')
            {
                flip(qu);
                ans = *R.begin();
                flip(ans);
            }
            else
            {
                //ans = que(1,1,n,1,qu);
                flip(qu);
                ef(1,qu,qu);
                flip(ans);
            }  
            
            printf("%d\n",ans);
        }
       
    }
        