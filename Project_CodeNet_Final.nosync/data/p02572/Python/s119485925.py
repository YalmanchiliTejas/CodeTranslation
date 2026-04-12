N = int(input())
As = list(map(int, input().split()))

sum = 0
for i in range(N):
    sum += As[i]
    sum %= 10**9+7

ans = 0
for i in range(N):
    sum -= As[i]
    ans += As[i]*sum
    ans %= 10**9+7

print(ans)
