import numpy as np

Height, Width = map(int, input().split())
mat = [[0 for i in range(Width)] for j in range(Height)]

for h in range(Height):
    a = input()
    
    for w in range(Width):
        if (a[w] == '.'):
            mat[h][w] = 0
        else:
            mat[h][w] = 1

mat = np.array(mat)

h_sur = []
w_sur = []

for h in range(Height):

    if (1 in mat[h]):
        h_sur.append(h)


for w in range(Width):

    if (1 in mat[:, w]):
        w_sur.append(w)


convert_w = len(w_sur)
convert_h = len(h_sur)

convert_mat = [[-1 for i in range(convert_w)] for j in range(convert_h)]
convert_mat=np.array(convert_mat)


for h_index, h in enumerate(h_sur):

    for w_index, w in enumerate (w_sur):

        convert_mat[h_index][w_index] = mat[h][w]


for i in range(convert_h):
    
    s=''
    for j in range(convert_w):
        if (convert_mat[i][j] == 1):
            s += '#'
        else:
            s += '.'
    
    print(s)
