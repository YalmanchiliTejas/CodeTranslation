n = int(input())
a = list(map(int, input().split()))

s = sum(a)
ans = 0
for i in a:
    s -= i
    ans += i * s
    ans %= 10 ** 9 + 7
print(ans)