n = int(input())
a = list(map(int, input().split()))
mod = 10**9 + 7

all_item = sum(a)

ans = 0
for i in range(n):
    all_item = (all_item - a[i])%mod
    ans = (ans + all_item*a[i])%mod
print(ans)
