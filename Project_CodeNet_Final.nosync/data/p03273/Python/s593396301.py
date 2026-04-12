h, w = map(int, input().split())
# print(h, w)

# matrix = []
# for _ in range(h):
#     row = input()
#     if '#' not in row:
#         continue
#     else:
#         matrix.append(row)

# print(matrix)

matrix = [input() for _ in range(h)]
# print(matrix)
matrix = [row for row in matrix if '#' in row]
# print(matrix)

T_matrix = [col for col in zip(*matrix) if '#' in col]
# print(T_matrix)

# T_matrix = []

# for col in zip(*matrix):
#     if '#' not in col:
#         continue
#     else:
#         T_matrix.append(col)

# for row in matrix:
#     print(row)
# for row in zip(*T_matrix):
#     print(''.join(row))

print(*(''.join(row) for row in zip(*T_matrix)), sep='\n')
