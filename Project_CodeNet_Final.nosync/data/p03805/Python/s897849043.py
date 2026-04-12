import copy

data = raw_input()

n,m = map(int,data.split(" "))

db = []
ans = 0

def search(pos,vis):
  global db
  global ans
  global n,m
  if len(vis) == n:
    ans = ans + 1
    return
  for x in db:
    if x[0] == pos:
      if x[1] not in vis:
        vis2 = copy.deepcopy(vis)
        vis2.append(x[1])
        search(x[1],vis2)

    if x[1] == pos:
      if x[0] not in vis and x[0] != 1:
        vis2 = copy.deepcopy(vis)
        vis2.append(x[0])
        search(x[0],vis2)


for x in range(m):
  data = raw_input()
  a,b = map(int,data.split(" "))
  db.append([a,b])

for x in db:
  if x[0] == 1:
    search(x[1],[1,x[1]])

print ans
