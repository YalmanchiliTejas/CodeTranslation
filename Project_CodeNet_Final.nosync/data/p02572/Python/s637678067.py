mod = int(1e9 + 7)
n = int(input())
a = input().split()
sum = 0
for x in a:
    sum += int(x)
sum %= mod
ans = 0
for x in a:
    sum -= int(x)
    ans += int(x) * sum
    ans %= mod
print(ans)