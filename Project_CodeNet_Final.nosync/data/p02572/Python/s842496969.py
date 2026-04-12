n = int(input())
a = list(map(int, input().split()))
MOD = 10 ** 9 + 7

s = sum(a) ** 2
t = sum(ai ** 2 for ai in a)
ans = (s - t) * pow(2, MOD - 2, MOD)
ans %= MOD
print(ans)