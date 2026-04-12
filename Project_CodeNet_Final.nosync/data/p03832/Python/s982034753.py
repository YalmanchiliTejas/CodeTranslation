class Combination:
    """階乗とその逆元のテーブルをO(N)で事前作成し、組み合わせの計算をO(1)で行う"""
    def __init__(self, n, MOD):
        self.fact = [1]
        for i in range(1, n + 1):
            self.fact.append(self.fact[-1] * i % MOD)
        self.inv_fact = [0] * (n + 1)
        self.inv_fact[n] = pow(self.fact[n], MOD - 2, MOD)
        for i in reversed(range(n)):
            self.inv_fact[i] = self.inv_fact[i + 1] * (i + 1) % MOD
        self.MOD = MOD

    def factorial(self, k):
        """k!を求める O(1)"""
        return self.fact[k]

    def inverse_factorial(self, k):
        """k!の逆元を求める O(1)"""
        return self.inv_fact[k]

    def permutation(self, k, r):
        """kPrを求める O(1)"""
        if k < r:
            return 0
        return (self.fact[k] * self.inv_fact[k - r]) % self.MOD

    def combination(self, k, r):
        """kCrを求める O(1)"""
        if k < r:
            return 0
        return (self.fact[k] * self.inv_fact[k - r] * self.inv_fact[r]) % self.MOD

    def combination2(self, k, r):
        """kCrを求める O(r) kが大きいが、r <= nを満たしているときに使用"""
        if k < r:
            return 0
        res = 1
        for l in range(r):
            res *= (k - l)
            res %= self.MOD
        return (res * self.inv_fact[r]) % self.MOD


n, a, b, c, d = map(int, input().split())
MOD = 10 ** 9 + 7
comb = Combination(10 ** 5, MOD)

dp = [[0] * (n + 1) for i in range(b - a + 2)]
dp[0][0] = 1

for i in range(b - a + 1):
    per_g = i + a
    for j in range(0, n + 1):
        dp[i + 1][j] = dp[i][j]
        for cnt_g in range(c, d + 1):
            if j - cnt_g * per_g < 0:
                break
            dp[i + 1][j] += dp[i][j - cnt_g * per_g] * comb.combination(j, cnt_g * per_g)\
                            * comb.factorial(cnt_g * per_g) * (pow(comb.inverse_factorial(per_g), cnt_g, MOD))\
                            * comb.inverse_factorial(cnt_g)
            dp[i + 1][j] %= MOD
print(dp[-1][-1])