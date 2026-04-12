N,X,M=map(int,input().split())

def f(x,m):
    return x%m

memo=[0 for i in range(M)]

A=[0 for i in range(100001)]
A[1]=X
memo[0]=1
memo[X]=1
b=0
s=1
for i in range(2,100001):
    A[i]=f(A[i-1]**2, M)
    if memo[A[i]]:
        memo[A[i]]=2
        b=A[i]
        s=i
        break
    else:
        memo[A[i]]=1

#周期突入前の部分を取得
mae=[]
m=0
while True:
    if A[m]==b and m!=0:
        break
    else:
        mae.append(A[m])
        m+=1
#print(mae)

#周期部分を取得
shuuki=A[len(mae):s]
if shuuki==[]:
    shuuki=[0]
#print(shuuki)

#print(b,s)


#周期数とあまりで答えを調整

ans=0
#1 周期に入る前におわるパターン
if N<=s-1:
    ans=sum(A[:N+1])
else:
    ans+=sum(mae)
    N-=len(mae)-1
    kai=N//len(shuuki)
    amari=N%len(shuuki)
    ans+=kai*sum(shuuki)
    ans+=sum(shuuki[:amari])

print(ans)