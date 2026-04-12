N=int(input())
A=list(map(int,input().split()))
mod = 10**9+7
S = [sum(A[1:])]
for a in A[1:-1]:
  S.append((S[-1]-a)%mod)
#print(S)
ans = 0
for a,s in zip(A,S):
  ans = (ans + a*s)%mod
print(ans)

