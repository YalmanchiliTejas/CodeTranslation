H,W = map(int,input().split())
A = [list(input()) for i in range(H)]
A_line = ['.'] * W
de_row = []
de_column = []
s = 0
t = 0
ind = 0
for a in A:
    if a == A_line:
        de_column.append(ind)
    ind += 1
for d in de_column:
    del A[d-s]
    s += 1

for i in range(W):
    flag = 0
    for j in range(len(A)):
        if A[j][i] == '.':
            flag += 1
            if flag == len(A):
                de_row.append(i)
            continue
        else:
            break

for d in de_row:
    for i in range(len(A)):
        del A[i][d-t]
    t += 1
for a in A:
    print(''.join(a))
