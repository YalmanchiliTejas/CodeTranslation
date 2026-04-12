n = int(input())
a = list(map(int, input().split()))
mod = 10 ** 9 + 7
s = sum(a)
ans = 0
for i in a[:n - 1]:
    s -= i
    ans += s * i
    ans %= 10 ** 9 + 7
print(ans)
