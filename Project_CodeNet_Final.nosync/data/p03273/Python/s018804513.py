h, w = map(int,input().split())

li = []

for i in range(h):
  wi = input()
  if wi.count('#') > 0:
    li.append(wi)

ans = [[0 for i in range(w)] for j in range(len(li))]
  
for i in range(w):
  line = []
  for j in range(len(li)):
    line.append(li[j][i])
  if line.count('#') != 0:
    for j in range(len(li)):
      ans[j][i] = line[j]

for i in ans:
  a = []
  for j in i:
    if j != 0:
      a.append(j)
  print(''.join(a))