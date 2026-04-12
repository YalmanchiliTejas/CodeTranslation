H, W = [int(item) for item in input().split()]

l = []
for i in range(H):
  line = input()
  if "#" in line: 
    l.append(line)
  else:
    H -= 1

to_be_deleted = []
for i in range(W):
  white = True
  for line in l:
    if line[i] == "#":
      white = False
      break
  if white:
    to_be_deleted.append(i)
    
for i in to_be_deleted[::-1]:
  for j in range(H):
    if i < W-1:
      l[j] = l[j][:i] + l[j][i+1:]
    else:
      l[j] = l[j][:i]
      
for item in l:
  print(item)