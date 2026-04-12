N=int(input())
A=list(map(int,input().split()))
ans=0
S=sum(A)
p= 10**9 +7
for i in range(N):
  S-=A[i]
  ans += (A[i]*S)%p
print(ans%p)
