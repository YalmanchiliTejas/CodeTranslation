from itertools import product

def upd(line, fix):
  for i, v in enumerate(fix):
   if v:
     if i == 0:
       line[i] = not line[i]
       line[i + 1] = not line[i + 1]
     elif i == 9:
       line[i - 1] = not line[i - 1]
       line[i] = not line[i]
     else:
       line[i - 1] = not line[i - 1]
       line[i] = not line[i]
       line[i + 1] = not line[i + 1]
  return list(map(int, line))

def upd2(line, fix):
  return [int(i != j) for i, j in zip(line, fix)]

n = int(input())
for _ in range(n):
  base_mp = [list(map(int, input().split())) for _ in range(10)]
  for first_row in product([0, 1], repeat=10):
    mp = [list(first_row)] + [[i for i in base_mp[j]] for j in range(10)]
    save = []
    for i in range(10):
      save.append(mp[i])
      mp[i + 1] = upd(mp[i + 1], mp[i])
      if i == 9:continue
      mp[i + 2] = upd2(mp[i + 2], mp[i])
    
    if not any(mp[10]):
      for line in save:
        print(*line)
      break

