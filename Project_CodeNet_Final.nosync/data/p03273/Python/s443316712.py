H,W=map(int,input().split())

board=[]
for i in range(H):
  board_=list(input())
  board.append(board_)

for i in range(H):
  if all([board[i][j]  == '*' or board[i][j]  == '.' for j in range(W)]):
    board[i]=['*']*W

for j in range(W):
  if all([board[i][j] =='*' or board[i][j] =='.' for i in range(H) ]):
    for k in range(H):
      board[k][j]='*'

Board=[[] for i in range(H)]
for i in range(H):
  for j in range(W):
    if board[i][j]!='*':
      Board[i].append(board[i][j])

for i in range(H):
  if Board[i]!=[]:
    print(''.join(Board[i]))
    
  else:
    continue