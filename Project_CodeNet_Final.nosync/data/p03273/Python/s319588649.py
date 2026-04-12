H, W = map(int, input().split())
a = []
for i in range(H):
    b = input()
    if "#" in b:
        a.append(b)
field = []
for j in range(W):
    c = ''
    for k in range(len(a)):
        c += a[k][j]
    if "#" in c:
        field.append(c)

length = len(field[0])
result = []
for k in range(length):
    newfield = ''
    for l in range(len(field)):
        newfield += field[l][k]
    print(newfield)