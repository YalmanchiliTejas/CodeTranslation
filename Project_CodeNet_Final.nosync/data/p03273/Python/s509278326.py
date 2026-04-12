H, W = map(int, input().split())
A = []
for _ in range(H):
    row = [{'.': 0, '#': 1}[c] for c in input()]
    if 0 < sum(row):
        A.append(row)
for x in range(W - 1, -1, -1):
    if sum(A[i][x] for i in range(len(A))) == 0:
        for y in range(len(A)):
            A[y][x:x + 1] = []
for row in A:
    print(''.join(['.' if v == 0 else '#' for v in row]))