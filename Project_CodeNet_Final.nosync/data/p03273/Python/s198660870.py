H, W = map(int, input().split())
a = [input() for _ in range(H)]

for i in range(H-1, -1, -1):
    if "#" not in a[i]:
        a.pop(i)

flag = False
for j in range(W-1, -1, -1):
    for i in range(len(a)):
        if a[i][j] == "#":
            flag = True
    if not flag:
        for i in range(len(a)):
            a[i] = a[i][:j] + a[i][j+1:]
    flag = False

for b in a:
    print(b)