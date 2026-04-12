N, M = map(int, input().split())
Path = [list(map(int, input().split())) for _ in range(M)]
import itertools

lis = [x for x in range(2, N+1)] 
ans = 0

permutations_lis = itertools.permutations(lis)

for one_case in permutations_lis:
  List = [1]
  List.extend(one_case)
  for i in range(N-1):
    if not ([List[i], List[i+1]] in Path or [List[i+1], List[i]] in Path):
      break
  else:
    ans += 1
print(ans)