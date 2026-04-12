from sys import stdin,setrecursionlimit
setrecursionlimit(10 ** 7)
h,w = map(int,stdin.readline().rstrip().split())
li = [["" for i in range(w)]for j in range(h)]
for i in range(h):
    s = stdin.readline().rstrip()
    for j in range(w):
        li[i][j] = s[j]
lin = []
for i in li:
    if i != ["."]*w:
        lin.append(i)
out = []
for i in range(w):
    flag = True
    for j in range(len(lin)):
        if lin[j][i] == "#":
            flag = False
    if flag:
        out.append(i)

lis = []
for i in lin:
    case = []
    for j,k in enumerate(i):
        if j in out:
            continue
        case.append(k)
    lis.append(case)

for i in lis:
    print("".join(i))