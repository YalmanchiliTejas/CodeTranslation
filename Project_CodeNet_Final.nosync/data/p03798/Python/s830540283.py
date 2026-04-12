N = int(input())
c = 0
S = list()
for i in input():
    if(i == 'o'): S.append(0)
    else: S.append(1)

for i in [0, 1]:
    if(c == 1): break
    for j in [0, 1]:
        t = list()
        t.append(i)
        t.append(j)

        for k in range(1, N-1):
            t.append(S[k] ^ t[k] ^ t[k-1])

        if(((S[0] ^ t[0] ^ t[-1]) == t[1]) & ((S[-1] ^ t[-1] ^ t[-2]) == t[0])):
            c = 1
            break

if(c == 1):
    ans = ""
    for i in t:
        if(i == 0): ans = ans + 'S'
        else: ans = ans + 'W'
    print(ans)
else:
    print('-1')