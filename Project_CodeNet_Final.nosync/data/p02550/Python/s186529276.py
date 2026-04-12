n,x,m=map(int,input().split())
# -1はまだ来てない
order=[-1 for i in range(m)]
index=0
#0,1,2,...　番目の数字を配列で記憶高々mこ
a=[]
while(order[x]==-1):
    order[x]=index
    a.append(x)
    x=(x**2)%m
    index+=1
#1周期の和
tmp=sum(a[order[x]:index])
T=index-order[x]
if(n-1<order[x]):
    print(sum(a[:n]))
else:
    #ループ前の和
    sum1=sum(a[:order[x]])
    #ループ前を全体から引いた数
    x1=n-order[x]
    #ループ回数
    n1=x1//T
    n2=x1%T
    print(sum1+n1*tmp+sum(a[order[x]:order[x]+n2]))
