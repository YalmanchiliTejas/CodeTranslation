N = int(input())
A = list(map(int, input().split()))
Asum = sum(A)
A2sum = 0
for i in range(N):
    A2sum += A[i]**2
print(((Asum**2-A2sum)//2)%(10**9+7))