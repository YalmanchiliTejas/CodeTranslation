N=int(input())
A=list(map(int,input().split()))
sum_mod=[0]
for i in range(N):
  sum_mod+=[(sum_mod[i]+A[i])%(10**9+7)]
ans=0
for i in range(N):
  ans=(ans+sum_mod[i]*A[i])%(10**9+7)
print(ans)