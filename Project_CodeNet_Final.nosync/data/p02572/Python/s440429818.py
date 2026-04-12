N = int(input())
A = list(map(int, input().split()))

MOD = 10**9 + 7
A_mod = [a%MOD for a in A]

R = sum(A_mod)

ans = 0

for a in A_mod:
    R -= a
    ans = (ans + a%MOD * R%MOD)%MOD
    
print(ans)