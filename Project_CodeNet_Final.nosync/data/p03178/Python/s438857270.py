K = int(input())
D = int(input())
MOD = 10**9 + 7

dp = [[[0]*D for _ in range(2)] for _ in range(int(len(str(K)))+1)]
dp[0][0][0] = 1

# 外側の要素から外側のループに置くと参照が速くなる
for digit in range(int(len(str(K)))):
    for smaller_flg in [0,1]:
        lim = 9 if smaller_flg else int(str(K)[digit])
        for digit_num in range(lim+1):
            new_smaller_flg = smaller_flg or digit_num < lim
            for mod_d in range(D):
                new_mod_d = (mod_d + digit_num)%D
                dp[digit+1][new_smaller_flg][new_mod_d] += dp[digit][smaller_flg][mod_d]
                dp[digit+1][new_smaller_flg][new_mod_d] %= MOD

print((dp[int(len(str(K)))][1][0] + dp[int(len(str(K)))][0][0] - 1) % MOD)