h,w = list(map(int,input().split()))

mat = []
for i in range(h):
    row = input()
    mat.append(row)

mat2 = []
for row in mat:
    isAllWhite = True
    for x in row:
        if x == '#':
            isAllWhite = False
            break
    if not isAllWhite:
        mat2.append(row)

hh = len(mat2)
mat3 = [[] for i in range(hh)]
for i in range(w):
    isAllWhite = True
    for j in range(hh):
        if mat2[j][i] == '#':
            isAllWhite = False
            break
    if not isAllWhite:
        for j in range(hh):
            mat3[j].append(mat2[j][i])

for row in mat3:
    print("".join(row))
