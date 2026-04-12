N = int(input())
A = list(map(int,input().split()))
S = 0
S2 = 0
MOD = 1000000007
for i in range(N):
  S += A[i]
  S2 += A[i]*A[i]
print((S*S-S2)//2%MOD)