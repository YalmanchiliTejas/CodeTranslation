N = int(input())
S = [input() for _ in range(N)]

dic = {}
for i in range(len(S[0])):
    if S[0][i] in dic:
        dic[S[0][i]] += 1
    else:
        dic[S[0][i]] = 1
for i in range(1, N):
    temp = {}
    for j in range(len(S[i])):
        if S[i][j] in temp:
            temp[S[i][j]] += 1
        else:
            temp[S[i][j]] = 1
    L = []
    for key in dic:
        if key in temp:
            dic[key] = min(dic[key], temp[key])
        else:
            L.append(key)
    for l in L:
        dic.pop(l)
            

L = []
for key in dic:
    L.append(key)
L.sort()
ans = ""
for l in L:
    ans += l*dic[l]
print(ans)