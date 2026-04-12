H, W = map(int, input().split())
a = []
for i in range(H):
    s = input()
    if s != '.'*W:
        a.append(s)
ls = []
for i in range(W):
    b = ''
    for j in range(len(a)):
        b += a[j][i]
    if b == '.'*len(a):
        ls.append(i)
ans = []
for i in range(len(a)):
    s = ''
    for j in range(W):
        if j in ls:
            continue
        else:
            s += a[i][j]
    ans.append(s)
print(*ans, sep='\n')