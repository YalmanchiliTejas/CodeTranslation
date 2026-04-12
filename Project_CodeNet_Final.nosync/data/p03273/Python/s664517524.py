H, W = map(int, input().split())
T = list(map(str, input()))
dic = {}
M = []
M.append(T)
for i in range(W):
    if T[i] == '.':
        dic[i] = 1
for i in range(H-1):
    T = list(map(str, input()))
    for j in range(W):
        if T[j] == '.' and j in dic:
            dic[j] += 1
    M.append(T)

for i in range(H):
    t = 0
    for j in range(W):
        if M[i][j] == '.':
            t += 1
        if j in dic and dic[j] == H:
            M[i][j] = ''
    if not t == W:
        print(''.join(M[i]))