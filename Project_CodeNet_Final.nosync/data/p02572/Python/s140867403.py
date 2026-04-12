N = int(input())

A = list(map(int,input().split()))

bubun = 0
ans = 0

for i in range(1, N):
    bubun += A[-i]
    ans += A[-(i + 1)] * bubun
    ans = ans % 1000000007

    
print(ans)