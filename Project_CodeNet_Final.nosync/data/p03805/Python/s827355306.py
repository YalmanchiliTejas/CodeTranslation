import itertools
n , m = map(int,input().split())
hen = [list(map(int,input().split())) for _ in range(m)]
#n , m = 3,3 # n頂点の数　m辺の数
#hen = [[1, 2], [1, 3], [2, 3]]

ans = 0
x = [i for i in range(2,n+1)]
candi = itertools.permutations(x)
for i in candi: #
  now = 1
  for next in i: # j 次の頂点
    if [now,next] in hen or [next,now] in hen:
      now = next
    else:
      ck = 0
      break
  else:
    ans += 1

print(ans)

