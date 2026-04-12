n, m = map(int, input().split())
a = [tuple(map(int, input().split())) for _ in range(m)]

sum_n = sum([i for i in range(n + 1)])

all_route = []
def dfs(i, r, o):
  route = r
  o_v = o
  route.append(i)
  o_v.append(i)
  v_num = [v[1] for v in a if v[0] == i and v[1] not in o_v]
  v_num += [v[0] for v in a if v[1] == i and v[0] not in o_v]
  if len(v_num) == 0:
    all_route.append(route[:])
    
  else:
    for v in v_num:
      dfs(v, route[:],o_v[:])    

dfs(1, [], [])
all_route_scores = [sum(route) for route in all_route]
r = all_route_scores.count(sum_n)

print(r)
  