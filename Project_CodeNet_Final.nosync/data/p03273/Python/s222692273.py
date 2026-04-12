h,w = [int(_) for _ in input().split()]
board = [ list(input())  for _ in range(h)]

goodx = [False] * h
goody = [False] * w

for i in range(h):
  for j in range(w):
#    print("i={}\tj={}\tboard={}".format(i,j,board[i][j]))
    if board[i][j] == '#':
      goodx[i] = True
      goody[j] = True

for i in range(h):
  if goodx[i]:
    for j in range(w):
      if goody[j]:
        print(board[i][j], end='')
    print("")