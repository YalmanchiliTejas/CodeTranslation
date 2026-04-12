H, W = map(int, input().split())
A = []
count = 0
for i in range(H):
    tmp = input() #入力は一文字として入ってくる
    if tmp == '.' * W:
        count += 1
    else:
        A.append(tmp)

skipp = []
for j in range(W):
    coucou = 0
    for i in range(H - count):
        if A[i][j] == '#':
            coucou = 1
            break
    if coucou == 0:
        skipp.append(j)
        
#出力
for i in range(H-count):
    for j in range(W):
        if j not in skipp:
            print(A[i][j], end = '')
    print()