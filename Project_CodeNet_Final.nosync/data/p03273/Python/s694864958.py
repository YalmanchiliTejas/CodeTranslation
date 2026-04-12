h,w = map(int,input().split())
a = [input() for _ in range(h)]
skip_w = []
for i in range(w):
    cnt = 0
    for j in range(h):
        if a[j][i] == '.':
            cnt += 1
    if cnt == h:
        skip_w.append(i)
for i in range(h):
    if a[i] == '.'*w:
        continue
    else:
        for j in range(w):
            if j not in skip_w:
                print(a[i][j], end='')
        print()
