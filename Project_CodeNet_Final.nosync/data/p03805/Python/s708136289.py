import itertools
n, m = map(int,input().split())
D = {tuple(sorted(map(int,input().split()))) for i in range(m)}
#print(D)
cnt = 0
for i in itertools.permutations(range(2,n+1),n-1):
  li = [1] + list(i)
  #print(li)
  cnt += sum(1 for j in zip(li,li[1:]) if tuple(sorted(j)) in D) == n-1
print(cnt)
