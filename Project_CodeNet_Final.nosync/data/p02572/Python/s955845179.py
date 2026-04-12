N = int(input())
A = [int(i) for i in input().split()]
S = 0
P = 10**9 + 7
for i in range(N):
  S = (S + A[i])%P
ans = 0
for i in range(N):
  S = (S-A[i]+P)%P
  a = (A[i]*S)%P
  ans = (ans + a)%P
print(ans)