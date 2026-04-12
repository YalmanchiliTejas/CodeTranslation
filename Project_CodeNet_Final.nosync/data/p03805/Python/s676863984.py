import itertools
n, m = map(int,input().split())
edges = {tuple(sorted(map(int,input().split()))) for i in range(m)}
#print(edges)
ans = 0
a = 0
for i in itertools.permutations(range(2, n+1), n-1):
  l = [1] + list(i)
  #print(l, l[1:])
  ans += sum(1 for edge in zip(l,l[1:]) if tuple(sorted(edge)) in edges) == n-1
  #print(sum(1 for edge in zip(l,l[1:]) if tuple(sorted(edge)) in edges) == n-1)
print(ans)