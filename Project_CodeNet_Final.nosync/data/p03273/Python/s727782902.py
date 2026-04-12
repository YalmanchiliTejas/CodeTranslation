h, w = map(int,input().split())
a = []

for i in range(h):
    s = input()
    if s != "."*w:
        a.append(s)

l = len(a)

ans = [[] for i in range(l)]

for i in range(w):
    for j in range(l):
        if a[j][i] == "#":
            for k in range(l):
                ans[k].append(a[k][i])
            break
for i in range(l):
    print("".join(ans[i]))