n = int(input())
As = list(map(int, input().split()))
MOD = 10**9 + 7
S = sum(As)
b = 0
for a in As:
    b += pow(a,2,MOD)
    b %= MOD
ans = (pow(S,2,MOD)-b)*pow(2,MOD-2,MOD)
print(ans%MOD)