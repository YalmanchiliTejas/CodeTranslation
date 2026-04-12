n = int(input())
slist = [input()for i in range(n)]

alp = {chr(i):float('inf') for i in range(97,97+26)}

for i in range(len(slist)):
    sdic = {chr(i):0 for i in range(97,97+26)}
    for j in range(len(slist[i])):
        sdic[slist[i][j]] += 1
    
    for k in alp:
        alp[k] = min(alp[k],sdic[k])

alplist = sorted(list(alp.items()))
ans = ''
for i in range(26):
    ans += alplist[i][0]*alplist[i][1]
print(ans)

