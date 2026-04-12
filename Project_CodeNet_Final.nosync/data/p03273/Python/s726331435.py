H, W = [int(n) for n in input().split()]

matrix = []

for i in range(H):
  matrix.append(list(input()))

white = ['.'] * W

pop_list = []
counter = 0

i = H - 1
while i >= 0:
  if matrix[i] == white:
    matrix.pop(i)
    counter += 1
  i -= 1

white = ['.'] * (H - counter)
i = W - 1
 
while i >= 0:
  current_col = [r[i] for r in matrix]
  if current_col == white:
    for j, r in enumerate(matrix):
      matrix[j].pop(i)
  i -= 1

for r in matrix:
  for rr in r:
    print(rr, end = '')
  print('\n')