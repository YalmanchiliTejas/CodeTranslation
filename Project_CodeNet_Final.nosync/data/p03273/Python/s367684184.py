H, W = list(map(int, input().split()))

a = [list(input()) for i in range(H)]

for i in reversed(range(len(a))):
  if '#' not in a[i]:
    del a[i]

a = list(zip(*a))
for i in reversed(range(len(a))):
  if '#' not in a[i]:
    del a[i]

a = list(zip(*a))
         
for i in a:
  print(''.join(i))