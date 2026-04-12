
while True:
  stones = [0, 0]
  n = input()
  if not n:
    break
  stones.append(input())
  stones.append(1)
  for i in range(n - 1):
    m = input()
    if i % 2 == 1:
      if stones[-2] == m:
        stones[-1] += 1
      else:
        stones.append(m)
        stones.append(1)
    else:
      if stones[-2] == m:
        stones[-1] += 1
      else:
        if len(stones) > 2:
          stones[-3] += stones[-1] + 1
          stones = stones[:-2]
        else:
          stones[-2] = m
          stones[-1] += 1
  ans = 0
  for j in range(0, len(stones), 2):
    if stones[j] == 0:
      ans += stones[j + 1]
  print ans