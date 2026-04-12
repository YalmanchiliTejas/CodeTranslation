from sys import stdin
H, W = map(int, input().split())
A = []
for _ in range(H):
    A.append([x for x in input()])
AT = list(zip(*A))
tate = []
yoko = []

for i in range(H):
    if '#' in A[i]:
        tate.append(i)
for i in range(W):
    if '#' in AT[i]:
        yoko.append(i)

for i in tate:
    for j in yoko:
        print(A[i][j], end='')
    print('')
