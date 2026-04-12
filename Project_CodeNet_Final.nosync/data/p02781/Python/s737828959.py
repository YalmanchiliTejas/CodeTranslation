# 解説放送

def main():
    S = input()
    N = len(S)
    K = int(input())

    dp = [[[0] * 2 for _ in range(K + 1)] for _ in range(N + 1)]
    dp[0][0][0] = 1
    # dp[i][j][k]
    # i桁目まで決めてj個の非0を使って
    # k=0: そこまでの桁はSと一致
    # k=1: すでにS未満が確定

    for i, c in enumerate(S):  # 100
        for j in range(K + 1):  # 4
            for k in range(2):  # 2
                nd = int(c)
                for d in range(10):  # 10
                    ni, nj, nk = i + 1, j, k
                    if d != 0: nj += 1  # 次の桁の値dとして0以外を採用すると非0の個数njが増える
                    if nj > K: continue  # 非0の数字を使用してよい上限を超えており、加算対象ではない
                    if k == 0:  # そこまでSと一致しているとき
                        if d > nd: continue  # 次の桁の値dがS[i]を超えており、採用するとSを超えるため、加算対象ではない
                        if d < nd: nk = 1  # 次の桁の値dがs[i]を下回っており、採用すると未満が確定する
                    dp[ni][nj][nk] += dp[i][j][k]

    print(sum(dp[N][K]))


if __name__ == '__main__':
    main()
