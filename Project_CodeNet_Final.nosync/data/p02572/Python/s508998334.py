n = int(input())
alst = list(map(int, input().split()))
ans = (sum(alst) ** 2 - sum([a ** 2 for a in alst])) // 2
MOD = 10 ** 9 + 7
print(ans % MOD)
