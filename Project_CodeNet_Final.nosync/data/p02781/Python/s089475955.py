# input
N = int(input())
K = int(input())

# defnition
N_bin = str(N)
digit_len_N = len(N_bin)
DP = [[[0]*(K+2) for _ in range(2)] for _ in range(digit_len_N+1)]
# DP[i][j][k]は、上位i桁目までで、(j==0 ?Nと同じになる可能性あり:必ずNより小さくなる)の時に、0以外の数がkこ出現する、数字の数


# initialize
DP[0][0][0] = 1

# solve with けたDP
for digit in range(digit_len_N):
    max_digit = int(N_bin[digit])
    for smaller in range(2):  # smaller=0?Nと同じになる可能性あり:Nより小さいの確定
        for k in range(K+1):
            cand_digits = max_digit+1 if smaller == 0 else 10  # 小さい確定なら0~9の全部が候補
            for next in range(cand_digits):
                if next == max_digit and smaller == 0:  # Nと同じになる可能性を残しつつ
                    if next == 0:  # 0のときは,kの値が増えないので特別扱い
                        DP[digit+1][0][k] += DP[digit][0][k]
                    else:
                        DP[digit+1][0][k+1] += DP[digit][0][k]
                else:  # ここで、Nより必ず小さい道に行く
                    if next == 0:  # 0のときは,kの値が増えないので特別扱い
                        DP[digit+1][1][k] += DP[digit][smaller][k]
                    else:
                        DP[digit+1][1][k+1] += DP[digit][smaller][k]
print(DP[-1][0][K]+DP[-1][1][K])
