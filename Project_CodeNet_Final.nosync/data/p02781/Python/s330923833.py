n = input()
k = int(input())

keta = len(n)

# dp0 = ヨユーなやつ, dp1 = ギリなやつ
dp0 = [[0 for j in range(keta+1)] for i in range(keta+1)]
dp1 = [[0 for j in range(keta+1)] for i in range(keta+1)]

dp1[0][0] = 1

for i in range(keta):
    for j in range(keta+1):
        # ギリギリのやつ(dp1)の処理
        if n[i] == '0': # i+1桁目が0の場合
            dp1[i+1][j] = dp1[i][j] # 真上からスライド
        else: # i+1桁目が1~9の場合
            if j < keta:
                dp1[i+1][j+1] = dp1[i][j] # 左上からスライド
        
        # ヨユーなやつ(dp0)の処理
        if n[i] == '0': # i+1桁目が0の場合
            # i桁目がヨユーな状態ではi+1桁目には何でも入れられる
            dp0[i+1][j] += dp0[i][j] # i+1桁目に0を入れた場合
            if j < keta:
                dp0[i+1][j+1] += dp0[i][j] * 9 # i+1桁目に1~9を入れた場合
            # i桁目までギリだったときの、i+1桁目のヨユーなやつのカウント
                # 何もない(ギリである0しか入れられないため)
        else: # i+1桁目が1~9の場合
            # i桁目がヨユーな状態ではi+1桁目には何でも入れられる
            dp0[i+1][j] += dp0[i][j] # i+1桁目に0を入れた場合
            if j < keta:
                dp0[i+1][j+1] += dp0[i][j] * 9 # i+1桁目に1~9を入れた場合
            # i桁目までギリだったときの、i+1桁目のヨユーなやつのカウント
            dp0[i+1][j] += dp1[i][j] # i+1桁目に0を入れた場合
            if j < keta:
                dp0[i+1][j+1] += dp1[i][j] * (ord(n[i])-ord('0')-1) # i+1桁目にrange(1, n[i])を入れた場合

if k > keta:
    print(0)
else:
    print(dp0[keta][k] + dp1[keta][k])