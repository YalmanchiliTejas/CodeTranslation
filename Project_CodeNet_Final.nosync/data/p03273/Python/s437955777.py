H, W = input().split()
H = int(H)
W = int(W)

mas = []

for i in range(H):
    a = input()
    if a == '.'*W:
        continue
    mas.append(a)

delFlg = False
delcache = []
for i in range(W):
    delFlg = True
    for x in mas:
        if x[i] != '.':
            delFlg = False
            break
    if delFlg:
        delcache.append(i)
delcache.sort(reverse=True)

for i in delcache:
    for j,x in enumerate(mas):
        mas[j] = x[0:i] + x[i+1:]

for x in mas:
    print(x)