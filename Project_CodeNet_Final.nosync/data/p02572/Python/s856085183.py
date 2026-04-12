n = int(input())
a = [int(a) for a in input().split()]
mod = 10**9 + 7
sums = sum(a)
ans = 0
for i in a:
    sums -= i
    ans += i * sums
    ans %= mod
print(ans)