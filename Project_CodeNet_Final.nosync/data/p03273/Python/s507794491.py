H, W  = map(int, input().split())

A = [[x for x in str(input())] for _ in range(H)]

x = 0
for h in range(H-1, -1, -1):
    if A[h].count('.') == W:
        del A[h]
        x += 1

for w in range(W-1, -1, -1):
    count = 0
    for h in range(H-x):
        if A[h][w] == '.':
            count += 1
    if count == H-x:
        for h in range(H-x-1, -1, -1):
            del A[h][w]

for h in range(H-x):
    print(''.join(A[h]))