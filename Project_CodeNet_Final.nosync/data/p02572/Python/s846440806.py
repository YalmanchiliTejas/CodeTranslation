n = int(input())
ls = list(map(int, input().split()))
MOD = 10 ** 9 + 7

ans = 0
SUM = sum(ls)
for i in range(len(ls)):
    SUM -= ls[i]
    ans += ls[i] * SUM
print(ans%MOD)