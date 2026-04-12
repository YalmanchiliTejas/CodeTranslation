import numpy
H, W = [int(i) for i in input().split()]
A = numpy.array([list(input().strip()) for _ in range(H)])

row_space = []
col_space = []

for k, row in enumerate(A):
    if '#' not in row:
        row_space.append(k)

A_rot = numpy.rot90(A, k=-1)
for k, row in enumerate(A_rot):
    if '#' not in row:
        col_space.append(k)

A = numpy.delete(A, row_space, axis=0)
A = numpy.delete(A, col_space, axis=1)
ans = '\n'.join([''.join(row) for row in A])
print(ans)