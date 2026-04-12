rows, cols = map(int, input().split())
mat = [input() for _ in range(rows)]

print_row = [False for _ in range(rows)]
print_col = [False for _ in range(cols)]

for i in range(rows):
  for j in range(cols):
    if mat[i][j] == '#':
      print_row[i] = True
      print_col[j] = True

for i in range(rows):
  print_newline = False
  for j in range(cols):
    if print_row[i] and print_col[j]:
      print(mat[i][j], end="")
      print_newline = True
  if print_newline:
    print()
