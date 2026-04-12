n_str = input()
n = int(n_str)
n_digit = len(n_str)
k = int(input())

#割り算のやーつ
MOD = 1000000007

# 二項係数関連.
class COM():
    def __init__(self, MAX, MOD):
        self.MOD = MOD
        self.MAX = MAX
        self.fac = [1] * MAX
        self.finv = [1] * MAX
        inv = [1] * MAX
        for i in range(2, MAX):
            self.fac[i] = self.fac[i - 1] * i % MOD
            inv[i] = MOD - inv[MOD % i] * (MOD // i) % MOD
            self.finv[i] = self.finv[i - 1] * inv[i] % MOD
    def calc_COM(self, n, k):
        if n < k:
            return 0
        if n < 0 or k < 0:
            return 0
        if self.MAX <= n:
            return 0
        return self.fac[n] * (self.finv[k] * self.finv[n - k] % self.MOD) % self.MOD
    def calc_PER(self, n, k):
        if n < k:
            return 0
        if n < 0 or k < 0:
            return 0
        if self.MAX <= n:
            return 0
        return self.fac[n] * self.finv[n - k] % self.MOD
    def calc_FAC(self, n):
        if self.MAX <= n:
            return 0
        return self.fac[n]

com = COM(100, MOD)

ans = 0
if(n_digit < k):
    # 満たす物は無い.
    print(0)
else:
    # 最大桁数-1の桁の数について、何が入っても問題ないので、3箇所選んで1-9をそれぞれ選ぶ.
    ans += com.calc_COM(n_digit-1, k) * (9 ** k)
    # 最大桁の桁の数について.
    n_top = int(n_str[0])
    if(k-1 <= 0):
        # これで終わりだから自由
        ans += n_top
    else:
        # 最大桁がn_top未満なら残りは自由
        ans += (n_top - 1) * com.calc_COM(n_digit-1, k-1) * (9 ** (k-1))
        # 最大桁がn_topなら、残りは自由じゃない……
        n_sec = 0
        count = n_digit
        i = 1
        for nc in n_str[1:]:
            i += 1
            count -= 1
            n_sec = int(nc)
            if(n_sec > 0):
                break
        if(count >= k-1):
            # まだ可能性がある！
            # 次に来る1以上の数字がcountよりも先だったら二つとも自由
            ans += 1 * com.calc_COM(count-1, k-1) * (9 ** (k-1))
            # 次の1以上の数字がcountの位置に来る.
            if(k-2 <= 0):
                ans += 1 * n_sec # これで終わりだからその下は考えないでいいのじゃ.
            else:
                # 次に来る1以上の数字がn_sec未満なら残りは自由
                ans += 1 * (n_sec - 1) * com.calc_COM(count-1, k-2) * (9 ** (k-2))
                # 次に来る1以上の数字がn_secと同じなら、残りは自由じゃない……
                n_third = 0
                sec_count = count
                for nd in n_str[i:]:
                    sec_count -= 1
                    n_third = int(nd)
                    if(n_third > 0):
                        break
                if(sec_count >= k-2):
                    # まだ可能性がある！
                    # 最後の数字がsec_countよりも下の位置
                    ans += 1 * 1 * (sec_count-1) * 9
                    # 最後の数字がsec_countの位置
                    ans += 1 * 1 * n_third

    print(ans)
