import sys
input = sys.stdin.readline

h, w = [int(x) for x in input().split()]
a = []
for _ in range(h):
    b = list(input().rstrip())
    if '#' in b:
        a.append(b)
h = len(a)
c = [1]*w
for i in range(w):
    flag = 1
    for j in range(h):
        if a[j][i] == "#":
            flag = 0
            break
    if flag:
        c[i] = 0
ans = []
for i in range(h):
    res = []
    for j in range(w):
        if c[j]:
            res.append(a[i][j])
    ans.append("".join(res))
for i in ans:
    print(i)

