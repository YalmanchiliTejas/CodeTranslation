h, w = map(int, input().split())
mat = []
idx = []
mat2 = []
for i in range(h):
    tmp = input()
    if tmp.count('.') != w:
        mat.append(tmp)

###行と列を入れ替える
for i in range(w):
    tmp2 = ''
    for j in range(len(mat)):
        tmp2 += mat[j][i]
    mat2.append(tmp2)

mat.clear()
for i in range(len(mat2)):
    if mat2[i].count('.') != len(mat2[i]):
        mat.append(mat2[i])

for i in range(len(mat[0])):
    ans = ''
    for j in range(len(mat)):
        ans += mat[j][i]
    
    print(ans)