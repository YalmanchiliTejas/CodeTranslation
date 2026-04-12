h, w = map(int, input().split())
a = []
for i in range(h):
   tmp = input()
   a.append(tmp)

for i in range(0, max(h, w)):
   row = [x.count('.') for x in a]
   a = [x for x, k in zip(a, row) if k < len(x)]

   b = [list(x) for x in zip(*a)]
   line = [x.count('.') for x in b]
   b = [x for x, k in zip(b, line) if k < len(x)]
   a = [list(x) for x in zip(*b)]

for i in range(len(a)):
   for j in range(len(a[i])):
      print(a[i][j], end='')
   print()
