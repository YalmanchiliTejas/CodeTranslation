H,W = map(int,input().split())
A =[[0]*(W+2)] + [[0] + [0 if s=='.' else 1 for s in input()] + [0]  for _ in range(H)] + [[0]*(W+2)]
pos = [1,1]
A[1][1] = 0
while pos != [W,H]:
  if pos[1]<=H and A[pos[1]+1][pos[0]] == 1:
    A[pos[1]+1][pos[0]] = 0
    pos = [pos[0],pos[1]+1]
  elif pos[0]<=W and A[pos[1]][pos[0]+1] == 1:
    A[pos[1]][pos[0]+1] = 0
    pos = [pos[0]+1,pos[1]]
  else:
    print('Impossible')
    exit()
if sum([sum(row) for row in A]) == 0: print('Possible')
else:print('Impossible')
