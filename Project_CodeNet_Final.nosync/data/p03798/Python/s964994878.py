import copy

def sol(animals):
  for i, rep in enumerate(reps[:N-2]):
    if i == 0: continue
    if animals[i] == 1:animals[i+1] = rep*animals[i-1]
    else:animals[i+1] = -rep*animals[i-1]

  if animals[-2] == 1 and animals[-1] != reps[-2]*animals[-3]: return False
  elif  animals[-2] == -1 and animals[-1] != -reps[-2]*animals[-3]: return False
      
  if animals[-1] == 1 and animals[0] != reps[-1]*animals[-2]:return False
  elif animals[-1] == -1 and animals[0] != -reps[-1]*animals[-2]: return False

  return animals

N = int(input())
reps = [1 if s=='o' else -1 for s in input()]
animals = [0 for _ in range(N)]

if reps[0] == 1:
  cases = [[1,1,1], [-1,1,-1],[1,-1,-1],[-1,-1,1]]
else:
  cases = [[-1,1,1],[1,1,-1],[1,-1,1],[-1,-1,-1]]
  
for case in cases:
  animals1 = copy.deepcopy(animals)
  animals1[-1],animals1[0],animals1[1] = case #1,1,1
  res = sol(animals1)
  if res is not False:
    print(''.join(['S' if s==1 else 'W' for s in res]))
    exit()
print(-1)
