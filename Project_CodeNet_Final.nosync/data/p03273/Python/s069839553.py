h,w = map(int,input().split())
a = []
for i in range(h):
    ans = str(input())
    a.append((ans))
a_h = []
for i in range(h):
    check_h = False
    for j in range(w):
        if a[i][j] == '#':
            check_h = True
    if check_h:
        a_h.append(a[i])
ans = ['']*len(a_h)
for i in range(w):
    check_w = False
    for j in range(h):
        if a[j][i] == '#':
            check_w = True
    if check_w:
        for k in range(len(a_h)):
            ans[k] += a_h[k][i]
for i in range(len(ans)):
    print(ans[i])