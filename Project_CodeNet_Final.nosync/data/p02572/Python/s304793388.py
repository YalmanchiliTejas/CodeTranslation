N = int(input())
A = list(map(int,input().split()))

Sum = sum(A)

ans = 0
for i in range(N-1):
    Sum = Sum - A[i]
    ans += int(A[i])*Sum

ans %= 1000000007

print(int(ans))
