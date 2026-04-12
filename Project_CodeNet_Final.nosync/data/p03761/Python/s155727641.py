import string

n = int(input())
sLst = list(input() for _ in range(n))

index = 0
tmp = 51
for i in range(n):
    if len(sLst[i]) <= tmp:
        tmp = len(sLst[i])
        index = i
alst = [0] * 26
for i in range(26):
    alst[i] = sLst[index].count(string.ascii_lowercase[i])

for i in range(26):
    if alst[i] != 0:
        mint = alst[i]
        tFlg = True
        for j in range(1, n):
            if sLst[j].count(string.ascii_lowercase[i]) == 0:
                tFlg = False
                break
            else:
                mint = min(mint, sLst[j].count(string.ascii_lowercase[i]))

        if tFlg:
            alst[i] = mint
        else:
            alst[i] = 0

ans = ''
for i in range(26):
    if alst[i] != 0:
        ans += alst[i] * string.ascii_lowercase[i]

print(ans)