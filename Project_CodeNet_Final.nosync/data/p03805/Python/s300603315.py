import itertools

n, m = map(int, input().split())
lsts = []
for _ in range(m):
  lsts.append(list(map(int, input().split())))
m = list(range(2, n + 1))
all = []
for v in itertools.permutations(m):
  l = [1] + list(v)
  all.append(l)
#print(all)

count = 0
for each in all:
  for i in range(n - 1):
    flag = False
    pos_1 = each[i]
    pos_2 = each[i + 1]
    for lst in lsts:
      if (pos_1 == lst[0] and pos_2 == lst[1]) or (pos_1 == lst[1] and pos_2 == lst[0]):
        flag = True
        break
    if not flag:
      break
  if flag:
    count += 1
print(count)