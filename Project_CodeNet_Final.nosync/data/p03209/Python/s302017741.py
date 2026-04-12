n,x=map(int,input().split())
B=[1] #レベルiバーガーの厚さ
P=[1] #レベルiバーガーのパティの数
for i in range(n-1):
    B.append(B[-1]*2+3)
    P.append(P[-1]*2+1)
ans=0
for i in range(n):
    if x==1:
        break
    elif 1<x<B[n-i-1]+2:
        x-=1
    elif x==B[n-i-1]+2:
        ans+=P[n-i-1]+1
        break
    elif x>B[n-i-1]+2:
        ans+=P[n-i-1]+1
        x-=B[n-i-1]+2
    else:
        ans+=2*P[n-i-1]+1
        break
else:
    ans+=1
print(ans)