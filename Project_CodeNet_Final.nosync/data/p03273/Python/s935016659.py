import numpy as np

H, W = map(int,input().split())

board = []
arr = np.empty((0,W),str)

for i in range(H):
  string = list(str(input()))
  board.append(string)
  arr = np.append(arr, np.array([string]), axis=0)

delete_h = []
delete_w = []
for i in range(H):
  cc = 0
  for j in range(W):
    if board[i][j] == "#":
      cc += 1
  if cc == 0:
    delete_w.append(i)

for i in range(W):
  cc = 0
  for j in range(H):
    if board[j][i] == "#":
      cc += 1
  if cc == 0:
    delete_h.append(i)
    
delete_w.reverse()
delete_h.reverse()

for i in delete_h:
  arr = np.delete(arr, i, 1)

for i in delete_w:
  arr = np.delete(arr, i, 0)

for i in range(H-len(delete_w)):
  print("".join(arr[i]))



