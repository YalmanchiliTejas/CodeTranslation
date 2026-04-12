num = list(map(int, input().split()))

grid = []
del_i = []
del_n = []

for i in range(num[0]):
  grid.append(list(input()))

  if "#" in grid[i] and "." in grid[i]:
    continue
  elif "#" in grid[i]:
    continue
  else:
    del_i.append(i)

check_1, check_2 = 0, 0

for n in range(num[1]):
  check_1, check_2 = 0, 0
  for i in range(num[0]):
    if grid[i][n] == "#":
      check_1 += 1
      if check_2 > 0:
        break
      # if check_1 == num[0]:
      #   del_n.append(n)
    else:
      check_2 += 1
      if check_1 > 0:
        break
      if check_2 == num[0]:
        del_n.append(n)

for i in range(num[0]):
  if i in del_i:
    continue
  else:
    m = 0
    for n in del_n:
      n = n - m
      del grid[i][n]
      m += 1
    print(''.join(grid[i]))