def answer(matrix):
    h = len(matrix)
    w = len(matrix[0])
    P, IM = ("Possible", "Impossible")
    cp = [0, 0] # current position
    rightBottom = [len(matrix)-1, len(matrix[0])-1]
    while(True):
        matrix[cp[0]][cp[1]] = '.'
        # Up
        if cp[0] > 0 and matrix[cp[0]-1][cp[1]] == '#': return IM
        # Left
        if cp[1] > 0 and matrix[cp[0]][cp[1]-1] == '#': return IM
        # Bottom
        if cp[0]+1 < h and matrix[cp[0]+1][cp[1]] == '#':
            if cp[1]+1 < w and matrix[cp[0]][cp[1]+1] == '#':
                return IM
            cp[0] = cp[0]+1
            continue
        # Right
        if cp[1]+1 < w and matrix[cp[0]][cp[1]+1] == '#':
            cp[1] = cp[1]+1
            continue
        if cp[0] == rightBottom[0] and cp[1] == rightBottom[1]:
            return P
    return P

h, w = map(int, input().split())
matrix = []
for _ in range(h):
    row = [c for c in input()]
    matrix.append(row)
print(answer(matrix))