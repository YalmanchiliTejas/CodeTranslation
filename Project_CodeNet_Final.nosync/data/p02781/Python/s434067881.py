n = input()
k = int(input())

D = [[[0] * (k+1) for i in range(len(n))] for j in range(2)]

D[0][0][0] = 1
D[0][0][1] = int(n[0]) - 1
D[1][0][1] = 1
kk = 1

for i in range(1, len(n)):
    D[0][i][0] = D[0][i-1][0]
    for j in range(1, k+1):
        D[0][i][j] += D[0][i-1][j-1] * 9 + D[0][i-1][j]
    if n[i] == "0":
        if kk < k+1:
            D[1][i][kk] += D[1][i-1][kk]
    else:
        if kk < k+1:
            D[0][i][kk] += D[1][i-1][kk]
        if kk+1 < k+1:
            D[1][i][kk+1] += D[1][i-1][kk]
            D[0][i][kk+1] += D[1][i-1][kk] * (int(n[i]) - 1)
        kk += 1

print(D[0][-1][-1] + D[1][-1][-1])
# print(D)