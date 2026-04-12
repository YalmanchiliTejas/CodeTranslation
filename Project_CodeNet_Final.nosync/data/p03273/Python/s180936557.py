l = [int(i) for i in input().split(" ")]
h = l[0]
w = l[1]
m = []

def trans(matrix):
    t_matrix = []
    h = len(matrix)
    w = len(matrix[0])
    for i in range(w):
        row = []
        for j in range(h):
            row.append(matrix[j][i])
        t_matrix.append(row)
    return t_matrix

def remove_dot(matrix):
    new_matrix = []
    for row in matrix:
        if "#" not in row:
            pass
        else:
            new_matrix.append(row)
    return new_matrix

for i in range(h):
    m.append(list(input()))
for i in range(2):
    m = remove_dot(m)
    m = trans(m)
for row in m:
    print("".join(row))
