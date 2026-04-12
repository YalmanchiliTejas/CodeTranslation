import sys
n = int(input())
a_ls = [int(i) for i in sys.stdin.readline().split()]
memo_ls = [[0 for j in range(n)] for i in range(n)]
for j in range(n):
    for i in range(j,-1,-1):
        if i == j:
            memo_ls[i][j] = a_ls[j]
        else:
            memo_ls[i][j] = max(- memo_ls[i+1][j] + a_ls[i], - memo_ls[i][j-1] + a_ls[j])
print(memo_ls[0][n-1])
