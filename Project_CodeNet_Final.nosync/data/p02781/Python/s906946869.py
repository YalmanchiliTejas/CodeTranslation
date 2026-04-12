


N = input()
K = int(input())
L = len(N)
"""
dp[i][j][k]：Nを頭からi桁まで見たとき、残りの使える0以外の個数がj個で、そこまでの値がNのi-1桁目までより小さい/同じ（小さいとk=1）時のi桁目までのとりうる個数
"""
dp = [[[0 for _ in range(2)] for _ in range(K+1)] for _ in range(L+1)]
dp[0][K][0] = 1

for i in range(L):
    digit = int(N[i])
    for num_rest_non_zero in range(K+1):
        for flag_less in range(2):
            """
            ・先頭はN[0]以下の値で決める
            ・もし現時点でNより小さいなら、次のi桁目は0以外の数字を使える個数に余裕があれば、
            i桁目に1~9まで使うこともできるし、0を使うこともできる
            ・既に0以外を使える個数がなくなって（使い切って）いれば、0をあてるしかない
            ・i-1桁目までがNと一致している（flag_less = 0）であれば、nのi桁目以下の値からしか選べない
            """

            # 先頭はN[0]以下の値しか選べない
            if i == 0:
                d = digit
            elif num_rest_non_zero == 0:
                d = 0
            elif flag_less == 1:
                d = 9
            else:
                d = digit

            for num in range(d+1):
                
                if flag_less == 0 and num == digit:
                    flag_less_nxt = 0
                else:
                    flag_less_nxt = 1

                # 0以外を使う場合
                if num != 0:
                    dp[i+1][num_rest_non_zero-1][flag_less_nxt] += dp[i][num_rest_non_zero][flag_less]
                else:
                    # i桁目に0をあてるので残数が減らない
                    dp[i+1][num_rest_non_zero][flag_less_nxt] += dp[i][num_rest_non_zero][flag_less]


print(sum(dp[L][0]))
#print(dp)