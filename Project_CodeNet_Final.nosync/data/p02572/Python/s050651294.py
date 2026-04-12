#C問題

#計算量の意識(O(N^2)では間に合わない)
#合同式-あまりの計算の性質
#a≡b ならば、a + c ≡　b + c, a - c ≡　b - c , a * c ≡　b * c 　つまり和差積については途中であまりを取って計算可能

MOD = 10**9 + 7
N = int(input())
A = list(map(int, input().split()))

S = sum(A) % MOD

ans = 0

#MODはいちいち取る癖をつける
for x in A:
    S -= x
    S %= MOD
    ans += S * x
    ans %= MOD
    
#MODは必要以上に取りすぎてもOK 忘れないためにもう一度
ans %= MOD

print(ans)
