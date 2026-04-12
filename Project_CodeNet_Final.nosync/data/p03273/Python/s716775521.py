H, W = map(int, input().split())
a = [list(input()) for i in range(H)]
A = [[0]*W for i in range(H)]
B = []
for i in range(H):
    for j in range(W):
        if a[i][j] == '#':
            A[i][j] += 1
    if sum(A[i]) > 0:
        B.append(A[i])

ans = [[] for i in range(len(B))]
for y in zip(*B):
    if sum(y) > 0:
        for i, x in enumerate(y):
            if x:
                ans[i].append('#')
            else:
                ans[i].append('.')
for x in ans:
    print(''.join(x))
