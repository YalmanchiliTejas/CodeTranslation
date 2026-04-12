import itertools
N, M = map(int, input().split())
l = []
seq = []
for i in range(1,N+1):
  seq.append(i)
  i+=1
for _ in range(M):
    A = list(map(int, input().split()))
    l.append(A)
cnt = 0
for i in list(itertools.permutations(seq)):
  if i[0]!=1:
    continue
  for j in range(N-1):
    if sorted([i[j],i[j+1]]) in l:
      if j == N-2:
        cnt += 1
    else:
      break
print(cnt)