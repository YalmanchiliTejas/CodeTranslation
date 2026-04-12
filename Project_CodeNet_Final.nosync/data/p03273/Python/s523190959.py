sus,fef = map(int,input().split())
r,c = [0]*sus,[0]*fef; 
duk,l,m = [],[],[]
for x in range(sus):
  cuc = input(); duk.append([c for c in cuc])
  r[x] = cuc.count('#')
  for j in range(fef):
    c[j] += 1 if cuc[j] == '#' else 0
for rt in range(sus):
  if not r[rt]: l.append(rt)
for gt in range(fef):
  if not c[gt]: m.append(gt)
for x in range(sus):
  if x in l: continue
  cucky = ''
  for y in range(fef):
    cucky += duk[x][y] if y not in m else ''
  print(cucky)