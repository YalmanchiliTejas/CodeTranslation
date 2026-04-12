# coding: utf-8
# Your code here!
# coding: utf-8
# Your code here!

MOD = 10**9+7

n=input()
D=int(input())

dp = [[[0 for _ in range(D)] for _ in range(2)] for _ in range(len(n)+1)] # 上からi桁まで、is_less, mod_D

dp[0][0][0] = 1
for i,ni in enumerate(n): #i桁目からi+1桁目に遷移
    ni = int(ni)
    for mod_d in range(D):
        for is_less in range(2):#1 なら真に小さい
            for d in range(10 if is_less else ni+1): # d: i+1桁目の数字
                dp[i+1][is_less or d < ni][(mod_d + d)%D] += dp[i][is_less][mod_d]
                dp[i+1][is_less or d < ni][(mod_d + d)%D] %= MOD
#    print(dp)

print((dp[-1][0][0] + dp[-1][1][0] - 1)%MOD)

