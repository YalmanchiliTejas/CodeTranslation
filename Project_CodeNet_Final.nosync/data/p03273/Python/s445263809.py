H, W = map(int, input().split())
T = [[] for i in range(H)]
for i in range(H):
    a = input()
    T[i] = a

S = []
for i in range(H):
    if T[i] == "." * W:
        continue
    else:
        S.append(list(T[i]))

m = len(S)
Z = [[] for i in range(m)]
for i in range(W):
    flag = False
    for j in range(m):
        if S[j][i] == "#":
            break
        if j == m - 1:
            flag = True
    if flag:
        continue
    else:
        for j in range(m):
            Z[j].append(S[j][i])

for i in range(m):
    print("".join(Z[i]))