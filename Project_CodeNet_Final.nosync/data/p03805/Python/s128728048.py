from itertools import permutations
N,M = map(int,input().split())
cc = [list(map(int,input().split())) for i in range(M)]
count = 0
for i in permutations([i+1 for i in range(N)],N):
  bb = 0
  if i[0] == 1:
    for j in range(N-1):
      aa = [i[j],i[j+1]]
      if aa in cc or aa[::-1] in cc:
        bb += 1
        if bb == N-1:
          count += 1
        continue
      else:
        break
print(count)     