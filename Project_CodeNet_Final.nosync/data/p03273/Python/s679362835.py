H, W = map(int, input().split())
matrix = [input() for i in range(H)]
matrix2 = [[i[j] for j in range(W)] for i in matrix if i != ''.join(['.'] * W)]
new_H = len(matrix2)
remove_col = ''.join(['.'] * new_H)
i = 0
while i < len(matrix2[0]):
  if ''.join([row[i] for row in matrix2]) == remove_col:
    list(map(lambda x: x.pop(i), matrix2))
  else:
    i += 1
 
print('\n'.join([''.join(i) for i in matrix2]))
