import itertools

n, m = map(int, input().split(" "))
path_city = [[] for _ in range(n)]
for _ in range(m):
  a, b = map(int, input().split(" "))
  path_city[a - 1].append(b - 1)
  path_city[b - 1].append(a - 1)
list_city = [i for i in range(1, n)]
list_order_city = itertools.permutations(list_city)

result = 0
for one_order in list_order_city:
  pre_city = 0
  flag_con = True
  for one_city in one_order:
    if pre_city not in path_city[one_city]:
      flag_con = False
      break
    pre_city = one_city
  if flag_con:
    result += 1
print(result)