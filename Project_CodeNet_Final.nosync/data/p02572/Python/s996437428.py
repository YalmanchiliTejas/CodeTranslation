n = int(input())
lis = list(map(int, input().split()))

m = 10**9 + 7
s = 0
for i in lis:
    s += i
    s %= m

ans = 0
for i in lis:
    s -= i
    ans += i * s
    ans %= m

print(ans)