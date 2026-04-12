h, w = map(int, input().split())
a = [list(input()) for i in range(h)]
del_list = []
n = 0
for i in range(h):
    for j in range(w):
        if a[i][j] == "#":
            break
    else:
        del_list.append(i)
for i in reversed(del_list):
    del a[i]
del_list = []
for j in range(len(a[0])):
    for i in range(len(a)):
        if a[i][j] == "#":
            break
    else:
        del_list.append(j)
for j in reversed(del_list):
    for i in range(len(a)):
        del a[i][j]
for i in range(len(a)):
    ans = ""
    for j in range(len(a[0])):
        ans += a[i][j]
    print(ans)
