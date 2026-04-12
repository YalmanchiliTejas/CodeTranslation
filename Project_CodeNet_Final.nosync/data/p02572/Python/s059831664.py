N = int(input())
A = list(map(int,input().split()))
Asum = 0
A2sum = 0

for p in range(N):
    Asum += A[p]
    A2sum += A[p]**2


print(((Asum**2-A2sum)//2)%(10**9+7))

