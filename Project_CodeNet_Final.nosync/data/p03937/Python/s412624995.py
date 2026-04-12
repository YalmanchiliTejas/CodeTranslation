H, W = map(int, input().split())
matrix = [[0 for i in range(W)] for j in range(H)]

for i in range(H):
  inp = input()
  for j, square in enumerate(inp):
    if square == '#':
      matrix[i][j] = 1
      
hw = [0, 0]
matrix[0][0] = 0
while True:
  # 右に行ければ右に行く
  if hw[1] + 1 < W and matrix[hw[0]][hw[1] + 1] == 1:
    matrix[hw[0]][hw[1] + 1] = 0
    hw = [hw[0], hw[1] + 1]
    continue
  
  # 右に行けない時、下に行ければ下に行く
  if hw[0] + 1 < H and matrix[hw[0] + 1][hw[1]] == 1:
    matrix[hw[0] + 1][hw[1]] = 0
    hw = [hw[0] + 1, hw[1]]
    continue
  
  # 右にも下にも行けなくなったらbreak
  else:
    break
    
flag = sum([sum(row) for row in matrix])
print("Impossible" if flag else "Possible")