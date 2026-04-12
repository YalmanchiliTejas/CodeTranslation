N = int(input())
A = list(map(int,input().split()))

MOD = 1000000007
SUM = 0
for i in range(N):
  SUM += A[i]
SUM = SUM*SUM
for i in range(N):
  SUM -= A[i]*A[i]
SUM = SUM // 2
SUM %= MOD
print(SUM)
    