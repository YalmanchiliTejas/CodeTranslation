N = int(input())
A = list(map(int, input().split()))
inf = 10**9+7
aa = [0]*N

for i in range(N):
  aa[i] = A[i]**2
X = sum(A)**2 - sum(aa)
print((X//2)%inf)