H, W = map(int, input().split())
ar = []
for i in range(H):
    ar.append([i for i in input().split()])

ar_true = []
for i in range(H):
    if ar[i] != ['.'*W]:
        ar_true.append(ar[i])

ar_res_line = []
n_length = len(ar_true)
for i in range(W):
    flag = False
    for ii in range(n_length):
        if ar_true[ii][0][i] == '#':
            flag = True
    if flag:
        ar_res_line.append(i)

ar_res = []
for h in range(n_length):
    tmp = ''
    for i in range(len(ar_res_line)):
        tmp_line = ar_res_line[i]
        tmp += ar_true[h][0][tmp_line]
    ar_res.append(tmp)

for i in range(n_length):
    print(ar_res[i])