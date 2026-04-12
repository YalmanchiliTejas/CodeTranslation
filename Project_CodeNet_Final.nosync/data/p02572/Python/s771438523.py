import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
a = list(map(int, input().split()))

MOD = 10**9+7

sum_j = 0
for v in a:
    sum_j += v
    sum_j %= MOD

ans = 0
for v in a:
    ans += v * ((sum_j - v) % MOD)
    ans %= MOD

# 重複削除
class FLT:
    """
    フェルマーの小定理
    a^(-1) = a^(m-2) mod p
    """
    def __init__(self, mod=10**9+7):
        self.mod = mod

    def rep_sqr(self, base, k):
        ans = 1
        while k > 0:
            if k & 1:
                ans = ans * base % self.mod
            base = base * base % self.mod
            k >>= 1
        return ans

    def inv(self, a):
        """ 逆元を取る """
        return self.rep_sqr(a, self.mod-2)

flt = FLT()

ans = ans * flt.inv(2)
ans %= MOD
print(ans)