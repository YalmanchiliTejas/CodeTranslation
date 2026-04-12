n = int(input())
li = list(map(int, input().split()))
mod = 10**9 + 7
ans = 0

for i in range(1, n):
    ans += li[0]*li[i]

check = ans
for i in range(1, n):
    if li[i-1] == 0:
        continue
    check -= li[i] * li[i-1]
    check //= li[i-1]
    check *= li[i]
    ans += check
    ans %= mod

print(ans)
