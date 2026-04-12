h,w = [int(i) for i in input().split()]

grid = [[1 if i == '#' else 0 for i in input()] for _ in range(h)]

total = 0
for i in grid:
  total += sum(i)
  
  
if total == (h+w-1):
  print('Possible')
else:
  print('Impossible')