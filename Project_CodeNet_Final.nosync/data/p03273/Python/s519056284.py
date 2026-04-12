import numpy as np
H, W = map(int, input().split())
area = []
for _ in range(H):
  s = input()
  area.append(list(s))

counterh = []
area = [area[i] for i in range(len(area)) if area[i].count('.')!=len(area[i])]

counterw = [1 for i in range(len(area[0]))]
for j in range(len(area)):
  for k in range(len(area[0])):
    if area[j][k] == '#':
      counterw[k] *= 0
Answer = []
for item in area:
  item = [item[i] for i in range(len(item)) if counterw[i] == 0]
  Answer.append(item)    

for o in range(len(Answer)):
  print(''.join(Answer[o]))