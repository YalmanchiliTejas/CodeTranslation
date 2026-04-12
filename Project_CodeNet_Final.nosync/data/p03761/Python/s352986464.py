N = int(input())
L = [list(input()) for i in range(N)]
D = {}
for i in range(len(L)) :
    if i == 0 :
        for j in range(len(L[i])) :
            if L[i][j] not in D :
                D[L[i][j]] = 1
            else :
                D[L[i][j]] += 1
    else :
        for k in D :
            if k not in L[i] :
                D[k] = 0
            else :
                D[k] = min(D[k], L[i].count(k))

D = sorted(D.items(),key=lambda x: x[0])
ANS = []
for i in range(len(D)) :
    ANS.append(D[i][0]*D[i][1])
ans = "".join(ANS)
print(ans)
