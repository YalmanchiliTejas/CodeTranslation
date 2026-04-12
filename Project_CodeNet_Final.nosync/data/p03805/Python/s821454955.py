n, m = map(int, input().split())
l = [list(map(int, input().split())) for _ in range(m)]
tree = [[] for _ in range(n)]
for i in l:
  tree[i[0]-1].append(i[1]-1)
  tree[i[1]-1].append(i[0]-1)
l = [i for i in range(n)]
global ans
ans = 0
def search(now, moved):
  moved.sort()
  if moved == l:
    global ans
    ans += 1
  for i in tree[now]:
    if i in moved:
      continue
    search(i, moved + [i])
  
search(0, [0])
print(ans)