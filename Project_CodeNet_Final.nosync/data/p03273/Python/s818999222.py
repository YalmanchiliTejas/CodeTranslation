h,w = map(int,input().split())
a = [input() for i in range(h)]
removeh = []
removew = []
for i in range(h):
    if not "#" in a[i]:
        removeh.append(i)
for i in range(w):
    flag = 0
    for j in range(h):
        if a[j][i] == "#":
            flag = 1
            break
    if flag == 0:
        removew.append(i)

for i in range(h):
    if removeh.count(i) == 0:
        buf = ""
        for j in list(set(range(w)) - set(removew)):
            buf += a[i][j]
        print(buf)