n = int(input())
li = list(map(int,input().split()))
mod = 10**9+7

sum = 0
for i in range(0,n):
    sum += li[i]
    sum %= mod

ans = 0
for i in range(0,n):
    sum -= li[i]
    if sum < 0:
        sum += mod
    ans += li[i] * sum
    ans %= mod
print(ans)