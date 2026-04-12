mod=10**9+7
A=int(input())
B=list(map(int,input().split()))
sum_n=sum(B)
ans=0
tmp=sum_n
for i in range(A):
   tmp-=B[i]
   ans+=B[i]*tmp%mod
   ans=ans%mod
print(ans)