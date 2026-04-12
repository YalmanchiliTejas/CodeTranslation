H, W = map(int, input().split())
matrix = [list(input()) for j in range(H)]
#print(matrix)
A = []
for line in range(H):
    #print(matrix[line])
    if matrix[line].count('.') != W:
        A.append(matrix[line])
#print('after line:', A)
B = [] # extract rows
for row in range(W):
    flg = True
    for line in range(len(A)):
        if A[line][row] == '#':
            flg = False
    if flg == True:
        B.append(row)
#print(B)
C = []
for line in range(len(A)):
    for b in sorted(B, reverse=True):
        A[line].pop(b)
    C.append(A[line])
for c in C:
    print(''.join(c))