H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

B = []
for h in range(H):
    if A[h].count('.') != W:
        B.append(A[h])

for c in range(W-1, -1, -1):
    for r in range(len(B)):
        if B[r][c] != '.':
            break
    else:
        for r in range(len(B)):
            del B[r][c]

for r in range(len(B)):
    print(''.join(B[r]))