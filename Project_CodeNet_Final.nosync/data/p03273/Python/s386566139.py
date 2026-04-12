H, W = list(map(int, input().split()))
squareA = [list(input()) for i in range(H)]
squareB = [[squareA[i][j] for i in range(H)] for j in range(W)]
h = []
w = []
for i in range(H):
  if '#' not in squareA[i]:
    h.append(i)
for i in range(W):
  if '#' not in squareB[i]:
    w.append(i)
for i in range(H):
  if i not in h:
    for j in range(W):
      if j not in w:
        print(squareA[i][j], end = "")
    print(end = "\n")