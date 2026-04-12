h, w = map(int, input().split())

matrix = []

for i in range(h):
  row = list(input())
  if '#' not in row:
    continue
  else:
    matrix.append(row)

removed_index = []

for i in range(len(matrix[0])):
  col = [row[i] for row in matrix]
  if '#' not in col:
    removed_index.append(i)

removed_index.reverse()

for n in removed_index:
  for row in matrix:
  	del row[n]

for row in matrix:
  print(''.join(row))
