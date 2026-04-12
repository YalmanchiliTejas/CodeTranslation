h,w = map(int,input().split())
a = []
for i in range(h):
    ai = input()
    if ai.count("#") >0:
        a.append(ai)

b = []
for i in range(w):
    b.append([])
    for j in range(len(a)):
            b[i].append(a[j][i])

c = []
for i in range(len(b)):
    if b[i].count("#")>0:
        c.append(b[i])

ans = []
for i in range(len(c[0])):
    ans.append([])
    for j in range(len(c)):
        ans[i].append(c[j][i])

for i in range(len(ans)):
    print("".join(ans[i]))