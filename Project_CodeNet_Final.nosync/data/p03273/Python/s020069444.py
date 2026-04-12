height, width = (int(x) for x in input().split())
matrix = []

for i in range(height):
  matrix.append(input())

row = [0] * width
column = [0] * height

for i in range(height):
  if '#' in matrix[i]:
    column[i] = 1
    for j in range(width):
      if (matrix[i][j] == '#'):
        row[j] = 1

for i in range(height):
  if (column[i] == 1):
    for j in range(width):
      if (row[j] == 1):
        print(matrix[i][j], end = '')
    print()
        