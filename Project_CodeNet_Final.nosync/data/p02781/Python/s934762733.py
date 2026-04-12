

ar = input()

k = int(input())

l = len(ar)


DP = [[[-1] * 2 for j in range(103)] for i in range(102)]


def dp(i, j, fl):
    if i == l:
        if j == k:
            return 1
        else:
            return 0

    if DP[i][j][fl] != -1:
        return DP[i][j][fl]

    res = 0

   # print(i,j,fl)
    if fl:
        for p in range(10):

            res += dp(i+1, j + (p != 0) , fl == 1)
    else:
        ko = ord(ar[i]) - ord('0')
        for p in range(ko + 1):

            res += dp(i + 1, j + (p != 0), p < ko)
    DP[i][j][fl] = res
    return res

print(dp(0, 0, 0))
