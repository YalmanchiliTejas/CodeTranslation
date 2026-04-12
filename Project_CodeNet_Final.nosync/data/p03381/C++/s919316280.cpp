#include<iostream>
#include<cstdio>
using namespace std;
int root;
struct node
{
    int d,c,f,son[2],n;/*d为值，f为父亲的编号，
    c为控制的节点个数，n为同值节点的个数*/
}tr[1001000];
int len;
void update(int x)//更新x所控制的节点数
{
    int ls=tr[x].son[0],rs=tr[x].son[1];
    tr[x].c=tr[ls].c+tr[rs].c+tr[x].n;
}
void add(int d,int f)//添加值为d的点，认f为父亲，同时，f认其为孩子
{
    len++;
    tr[len].d=d;tr[len].n=1;tr[len].f=f;
    tr[len].c=1;
    if(d<tr[f].d)
        tr[f].son[0]=len;
    else
        tr[f].son[1]=len;
    tr[len].son[0]=tr[len].son[1]=0;
} 
void rotate(int x,int w)//左旋(x,0),右旋(x,1) 
{
    int f=tr[x].f,ff=tr[f].f;//确定x的父亲和爷爷 
    int r,R;//r表示儿辈，R表示父辈
    //有四个角色，我x，我的儿子，我的父亲，我的爷爷
    r=tr[x].son[w];//x的儿子准备当新儿子 
    R=f;
    tr[R].son[1-w]=r;
    if(r!=0)
        tr[r].f=R;
     
    r=x;R=ff;//x准备当新儿子
    if(tr[R].son[0]==f)
        tr[R].son[0]=r;
    else
        tr[R].son[1]=r;
    tr[r].f=R;
     
    r=f;R=x;//x的父亲准备当新儿子
    tr[R].son[w]=r;
    tr[r].f=R;
     
    update(f);//先更新处于下层的f 
    update(x);//再更新上层的x 
}
void splay(int x,int rt)//此函数的作用是让x成为rt的儿子(左右均可) 
{
    while(tr[x].f!=rt)//若rt为x的父亲，则什么也不用做，否则x要不断向上旋转 
    {
        int f=tr[x].f,ff=tr[f].f;//准备x的父亲和爷爷 
        if(ff==rt)//若x的爷爷为rt，那么x只需旋转一次(向上跳一层) 
        {
            if(tr[f].son[0]==x)
                rotate(x,1);
            else
                rotate(x,0);
        }
        else
        {
            if(tr[ff].son[0]==f&&tr[f].son[0]==x)
            {
                rotate(f,1);
                rotate(x,1);
            }
            else if(tr[ff].son[1]==f&&tr[f].son[1]==x)
            {
                rotate(f,0);
                rotate(x,0);
            }
            else if(tr[ff].son[0]==f&&tr[f].son[1]==x)
            {
                rotate(x,0);
                rotate(x,1);
            }
            else if(tr[ff].son[1]==f&&tr[f].son[0]==x)
            {
                rotate(x,1);
                rotate(x,0);
            }
        }
    }
    if(rt==0)
        root=x;
} 
int findip(int d)//找到值为d的节点的地址，若不存在d，有可能是接近d的(或大或小) 
{
    int x=root;
    while(tr[x].d!=d)
    {
        if(d<tr[x].d)
        {
            if(tr[x].son[0]==0)
                break;
            else
                x=tr[x].son[0];
        }
        else
        {
            if(tr[x].son[1]==0)
                break;
            else
                x=tr[x].son[1];         
        }
    }
    return x; 
}
void ins(int d)//插入数值为d的一个节点
{
    if(root==0)
    {
        add(d,0);
        root=len;
        return;
    }
    int x=findip(d);
    if(tr[x].d==d)
    {
        tr[x].n++;
        update(x);
        splay(x,0);
    }
    else
    {
        add(d,x);
        update(x);
        splay(len,0);
    }
}
void del(int d)//删除值为d的一个点
{
    int x=findip(d);
    splay(x,0);
    if(tr[x].n>1)
    {
        tr[x].n--;
        update(x);
        return;
    }
    if(tr[x].son[0]==0&&tr[x].son[1]==0)
    {
        root=0;
        len=0;
    }
    else if(tr[x].son[0]==0&&tr[x].son[1]!=0)
    {
        root=tr[x].son[1];
        tr[root].f=0;
    }
    else if(tr[x].son[0]!=0&&tr[x].son[1]==0)
    {
        root=tr[x].son[0];
        tr[root].f=0;
    }
    else
    {
        int p=tr[x].son[0];
        while(tr[p].son[1]!=0)//找子树max值 
        	p=tr[p].son[1];
        splay(p,x);  
        int r=tr[x].son[1],R=p;
        tr[R].son[1]=r;
        tr[r].f=R;
         
        root=R;
        tr[root].f=0;
        update(R);
    }
}
int find_num(int d)//找排名
{
    int x=findip(d);
    splay(x,0);
    return tr[tr[x].son[0]].c+1;
} 
int find_d(int k)//找排名第k的数的值 
{
    int x=root;
    while(1)
    {
        int ls=tr[x].son[0],rs=tr[x].son[1];
        if(k<=tr[ls].c)//左子树 
            x=ls;
        else if(k>tr[ls].c+tr[x].n)//右子树 
        {
            k-=tr[ls].c+tr[x].n;
            x=rs;
        }
        else
            break;
    }
    splay(x,0);
    return tr[x].d;
}
int find_front(int d)//找前驱 
{
    int x=findip(d);
    splay(x,0);
    if(d<=tr[x].d&&tr[x].son[0]!=0)
    {
        x=tr[x].son[0];
        while(tr[x].son[1]!=0)
            x=tr[x].son[1];
    }
    if(tr[x].d>=d)
        x=0;
    return tr[x].d;
}
int find_behind(int d)//找后继
{
    int x=findip(d);
    splay(x,0);
    if(tr[x].d<=d&&tr[x].son[1]!=0)
    {
        x=tr[x].son[1];
        while(tr[x].son[0]!=0)
            x=tr[x].son[0];
    }
    if(tr[x].d<=d)
        x=0;
    return tr[x].d;
} 
int n;
int a[1001000];
int main()
{
    cin>>n;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		ins(a[i]);
	del(a[1]);
	printf("%d\n",find_d(n/2));
	for(int i=2;i<=n;++i)
	{
		ins(a[i-1]);
		del(a[i]);
		printf("%d\n",find_d(n/2));
	}
	return 0;
}