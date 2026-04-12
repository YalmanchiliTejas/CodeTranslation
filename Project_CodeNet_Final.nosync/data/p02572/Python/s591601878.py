N = int(input())
A = list(map(int, input().split()))
MOD = 10**9 + 7

AA = 0
ans = 0
for a in A:
    AA = (AA + pow(a, 2, MOD))%MOD
    ans = (ans + a%MOD)%MOD
inverse2 = pow(2, MOD-2, MOD)
ans = (((pow(ans, 2, MOD) - AA%MOD)%MOD)*inverse2)%MOD
print(ans%MOD)
