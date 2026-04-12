h,w = map(int, input().split())
ar = []
for _ in range(h):
  row = list(input())
  if row == ['.']*w:
    continue
  ar.append(row)

c = 0
while c < len(ar[0]):
  count = 0
  for r in range(len(ar)):
    if ar[r][c] == '#':
      count += 1
  if count == 0:
    for row in ar:
      row.pop(c)
  else:
    c += 1

for row in ar:
  print("".join(row))