h, w = map(int, input().split())
a = []
for _ in range(h):
    l = input()
    if l != '.'*w:
        a.append(l)
col = []
h = len(a)
for i in range(w):
    if a[0][i] == '.':
        for j in range(1,h):
            if a[j][i] != '.':
                col.append(i)
                break
    else:
        col.append(i)
for l in a:
    ll = ''
    for i in col:
        ll += l[i]
    print(ll)