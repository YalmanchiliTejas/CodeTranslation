h, w = map(int, input().split())
mapping = []
judge = "".join(["."]*w)
t = 0
for i in range(h):
  key = input()
  if key != judge:
    mapping.append([])
    for j in range(w):
      mapping[-1].append(key[j])
  else:
    t += 1

for i in range(w-1, -1, -1):
  for j in range(h-t):
    if mapping[j][i] == "#":
      break
    if j == h-t-1:
      for l in range(h-t):
        mapping[l].pop(i)

for i in range(h-t):
  print("".join(mapping[i]))