# AGC 007: A – Shik and Stone
H, W = [int(s) for s in input().split()]
A = [input() for _ in range(H)]

isExact = 'Possible'

i, j = 0, 0

while i < H - 1 or j < W - 1:
    if ((i + 1 < H and A[i + 1][j] != '#') and (j + 1 < W and A[i][j + 1] != '#')) \
            or (i + 1 == H and j + 1 < W and A[i][j + 1] != '#') \
            or (i + 1 < H and j + 1 == W and A[i + 1][j] != '#'):
        isExact = 'Impossible'
        break
    elif j + 1 < W and A[i][j + 1] == '#':
        A[i] = A[i][:j] + '.' + A[i][j + 1:]
        j += 1
    elif i + 1 < H and A[i + 1][j] == '#':
        A[i] = A[i][:j] + '.' + A[i][j + 1:]
        i += 1

if isExact == 'Possible':
    A[H - 1] = A[H - 1][:W - 1] + '.'

    for line in A:
        if '#' in line:
            isExact = 'Impossible'
            break

print(isExact)