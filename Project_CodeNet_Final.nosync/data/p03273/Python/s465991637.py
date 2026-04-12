from operator import itemgetter

H, W = map(int, input().split())

A = []
Hnew = 0
for i in range(H):
    temp = input()
    if temp == '.' * W:
        pass
    else:
        A.append(temp)
        Hnew += 1

FlagA = [0] * W

for i in range(W):
    for j in range(Hnew):
        if A[j][i] == '#':
            FlagA[i] = 1
            break

for i in range(Hnew):
    for j in range(W):
        if FlagA[j] == 1:
            print(A[i][j], end="")
    print()
