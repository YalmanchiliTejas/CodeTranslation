n,x=map(int,input().split())

#レベルNの層とパティの数を求める
a,p=[1],[1]
for i in range(n):
    a.append(2*a[i]+3)
    p.append(2*p[i]+1)

def cnt(n,x):
    #レベルNのバーガーのX層までに含まれるパティを数える
    if n==0:
        return 1 if x>=1 else 0

    elif x<=1+a[n-1]:
        return cnt(n-1,x-1)

    elif 2+a[n-1]<=x:
        return cnt(n-1,x-(a[n-1]+2))+p[n-1]+1

print(cnt(n,x))