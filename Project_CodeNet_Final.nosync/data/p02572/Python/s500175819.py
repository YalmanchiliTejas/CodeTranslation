N = int(input())
A = list(map(int, input().split()))

A_sum = sum(A)
B = [0]*N

for i in range(N):
  B[i] = A[i]**2
  

ans = (A_sum**2 - sum(B))//2%(10**9+7)

print(ans)