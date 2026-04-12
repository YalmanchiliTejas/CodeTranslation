# input
N = int(input())
K = int(input())

# defnition
N_bin = str(N)
bit_len_N = len(N_bin)
DP = [[[0]*(K+2) for _ in range(2)] for _ in range(bit_len_N+1)]
# Kは0でない数の数
# smaller=0はboarder

DP[0][0][0] = 1

# solve with けたDP
for bit in range(bit_len_N):
    max_digit = int(N_bin[bit])
    for smaller in range(2):
        for k in range(K+1):
            cand_digits = max_digit+1 if smaller == 0 else 10
            for next in range(cand_digits):
                if next == max_digit and smaller == 0:
                    if next == 0:
                        DP[bit+1][0][k] += DP[bit][0][k]
                    else:
                        DP[bit+1][0][k+1] += DP[bit][0][k]
                else:
                    if next == 0:
                        DP[bit+1][1][k] += DP[bit][smaller][k]
                    else:
                        DP[bit+1][1][k+1] += DP[bit][smaller][k]
print(DP[-1][0][K]+DP[-1][1][K])
