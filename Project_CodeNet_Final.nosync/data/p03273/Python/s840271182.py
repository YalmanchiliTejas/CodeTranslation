H,W = map(int,input().split())
A=[]
for i in range(H):
    A.append(list(input()))

for i in range(H):
    if A[i] == ['.'] * W:
        A[i] = ['-1'] * W
for j in range(W):
    count = 0
    for i in range(H):
        if A[i][j] == '#':
            break
        count += 1
    if count == H:
        for i in range(H):
            A[i][j] = '-1'
for a in A:
    if a == ['-1'] * W:
        continue
    ans = [ai for ai in a if not ai == '-1']
    print(''.join(ans))


