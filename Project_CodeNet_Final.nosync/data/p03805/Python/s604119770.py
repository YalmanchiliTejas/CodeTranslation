import itertools
N, M = map(int, input().split())
l = []
seq = []
for i in range(N):
  seq.append(i)
  i+=1
for _ in range(M):
    a,b = list(map(int, input().split()))
    l.append([a-1,b-1])
cnt = 0
for i in list(itertools.permutations(seq)):
  if i[0]!=0:
    continue
  for j in range(N-1):
    if sorted([i[j],i[j+1]]) in l:
      if j == N-2:
        cnt += 1
    else:
      break
print(cnt)