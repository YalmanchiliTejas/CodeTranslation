N = int(input())
S = []
for i in range(N):
    S.append(input())

wod = set(S[0])
for i in range(1, N):
    wod = wod & set(S[i])
    
wod = sorted(wod)
check = [10000] * len(wod)


for i in range(len(wod)):
    for s in S:
        check[i] = min(check[i], s.count(wod[i]))

ans = ''

for i in range(len(wod)):
    ans += wod[i]*check[i]
print(ans)