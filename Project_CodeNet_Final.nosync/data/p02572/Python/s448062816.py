N = int(input())
A = list(map(int, input().split()))

ans = 0
tmp = 0
for i in range(N-2, -1, -1):
    tmp += A[i+1]
    ans += A[i] * tmp

print(ans % 1000000007)