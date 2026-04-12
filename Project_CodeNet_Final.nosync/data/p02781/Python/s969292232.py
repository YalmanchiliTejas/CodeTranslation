import sys
n = int(input())
k = int(input())
n_keta = len(str(n))
memo_ls = [[[0 for _k in range(2)] for j in range(k+2)] for i in range(n_keta + 1)] #フラグ1は小さいこと確定
memo_ls[0][0][0] = 1
for i, base in enumerate(str(n), 1):
    base = int(base)
    for j in range(10):
        for _k in range(k+1):
            if j > base:
                memo_ls[i][_k+1][1] += memo_ls[i-1][_k][1]
            elif j == base:
                if j == 0:
                    memo_ls[i][_k][0] += memo_ls[i-1][_k][0]
                    memo_ls[i][_k][1] += memo_ls[i - 1][_k][1]
                else:
                    memo_ls[i][_k+1][1] += memo_ls[i-1][_k][1]
                    memo_ls[i][_k+1][0] += memo_ls[i-1][_k][0]
            else:
                if j == 0:
                    memo_ls[i][_k][1] += memo_ls[i-1][_k][1] + memo_ls[i - 1][_k][0]
                else:
                    memo_ls[i][_k+1][1] += memo_ls[i-1][_k][1] + memo_ls[i-1][_k][0]
print(sum(memo_ls[-1][k]))