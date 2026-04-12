h,w = map(int,input().split())
a = [list(map(str,input())) for _ in range(h)]
cnt = h
for i in range(h):
    if '#' not in a[i]:
        a[i].clear()
        cnt -= 1
if cnt != h:
    a = [_ for _ in a if _]
i = 0
while i < w:
    for j in range(cnt):
        if a[j][i] == '#':
            break
    else:
        for j in range(cnt):
            a[j].pop(i)
        w -= 1
        i -= 1
    i += 1
for i in range(cnt):
    print(''.join(map(str,a[i])))