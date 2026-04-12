N = int(input())
A = list(map(int,input().split()))
s =0
M = 10**9 +7
As = sum(A)
for i in range(N-1):
  As = As - A[i]
  s += (A[i] * As)%M
print(s%M)