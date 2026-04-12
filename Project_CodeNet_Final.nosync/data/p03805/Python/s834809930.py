import itertools
n,m = map(int,input().split())
p = []
for i in range(m):
    p.append(list(map(int, input().split())))
l = [[] for i in range(n+1)]
for pi in p:
    l[pi[0]].append(pi[1])
    l[pi[1]].append(pi[0])
c = list(itertools.permutations(range(2,n+1), n-1))
ans = 0
for i in c:
  if i[0] not in l[1]:
    continue
  else:
    for j in range(1,len(i)):
      if i[j] not in l[i[j-1]]:
        break
    else:
      ans += 1
print(ans)
  