h, w=map(int, input().split())
s=[input() for i in range(h)]
nuee1=[]
nuee2=[]
for i in range(h):
  nuee=False
  for j in range(w):
    if s[i][j]=='#':
      nuee=True
      break
  nuee1.append(nuee)
for j in range(w):
  nuee=False
  for i in range(h):
    if s[i][j]=='#':
      nuee=True
      break
  nuee2.append(nuee)
for i in range(h):
  if not nuee1[i]:
    continue
  for j in range(w):
    if not nuee2[j]:
      continue
    print(s[i][j], end="")
  print()