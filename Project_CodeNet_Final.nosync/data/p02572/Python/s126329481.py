N=int(input())
*A,=map(int,input().split())
t=10**9+7
S=[a%t for a in A]
g=sum(S)

ans=0
for i in range(N):
       g-=S[i]
       ans+=S[i]*g%t
print(ans%t)    