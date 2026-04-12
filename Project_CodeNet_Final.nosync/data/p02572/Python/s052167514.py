N = int(input())
A = list(map(int, input().split()))
ruisekiwa = [0]
MOD = 10**9+7
for i in reversed(range(N)):
    ruisekiwa.append((ruisekiwa[-1]+A[i])%MOD)
ruisekiwa.reverse()
ruisekiwa = ruisekiwa[1:]
ans = 0
for i in range(N):
    ans += (A[i]%MOD)*ruisekiwa[i]
    ans %= MOD
print(ans)
