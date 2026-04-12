H,W = map(int, input().split())
matrix = []

for i in range(H):
    matrix.append(input())

newmat = []

for i in range(H):
    if matrix[i] == '.'*W:
        continue
    else:
        newmat.append(matrix[i])
        
printW = []
for x in range(W):
    for lin in newmat:
        if lin[x] == '#':
            printW.append(x)
            break
        
for lin in newmat:
    str = ''
    for w in printW:
        str += lin[w]
    print(str)