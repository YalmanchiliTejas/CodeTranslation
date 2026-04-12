h, w = map(int, input().split())
alist = [[a for a in input()] for i in range(h)]

alist1 = []
for row in alist:
  if '#' in row:
    alist1.append(row)

alist2 = []
for row in zip(*alist1):
  if '#' in row:
    alist2.append(row)

for row in zip(*alist2):
  print(''.join(row))