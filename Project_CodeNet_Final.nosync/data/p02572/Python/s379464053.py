n = int(input())

a = list(map(int, input().split()))
mod = (10 ** 9) + 7

total = sum(a)
ans = 0
for i in a:
    total -= i
    ans = (ans + (i * total)) % mod

print(ans)