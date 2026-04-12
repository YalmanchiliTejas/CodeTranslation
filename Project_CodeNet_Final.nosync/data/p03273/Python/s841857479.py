h, w = map(int, input().split())
m=[]
for _ in range(h):
  temp = input()
  if temp.count("#") == 0:
    continue
  m.append(temp)

ku=[]
for i in range(w):
  for j in m:
    if j[i] == "#":
      break
  else:
    ku.append(i)

k = list(set([i for i in range(w)]) - set(ku))
for i in m:
  temp=""
  for j in k:
    temp += i[j]
  print(temp)