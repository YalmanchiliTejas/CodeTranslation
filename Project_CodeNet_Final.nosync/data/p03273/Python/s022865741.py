h, w = map(int, input().split())
a = []
for i in range(h):
    t = list(input())
    a.append(t)
id = []
jd = []
for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            if i not in id:
                id.append(i)
            if j not in jd:
                jd.append(j)
jd.sort()
for i in id:
    for j in jd:
        print(a[i][j], end="")
    print()