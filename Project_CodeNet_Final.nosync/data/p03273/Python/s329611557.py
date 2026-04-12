h,w = map(int,input().split())
a = [input() for _ in range(h)]
b = []
for i in range(h):
    if a[i] != '.'*w:
        b.append(a[i])
ans = []
for i in range(w):
    flag = False
    for j in range(len(b)):
        flag |= b[j][i]=='#'
    if not flag:
        ans.append(i)
for i in b:
    for j,k in enumerate(i):
        if j not in ans:
            print(k,end='')
    print('')
