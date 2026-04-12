h, w = map(int, input().split())
retu = [0 for i in range(w)]
gyou = [0 for i in range(h)]
lst = []
for i in range(h):
    ai = input()
    kuro = 0
    for j in range(w):
        if ai[j] == '#':
            kuro = 1
            retu[j] = 1
    if kuro == 1:
        gyou[i] = 1
    lst.append(ai)

ans = []
for i in range(h):
    if gyou[i] == 0: continue
    temp = ''
    for j in range(w):
        if retu[j] == 1:
            temp += lst[i][j]
    ans.append(temp)

for temp in ans:
    print(temp)