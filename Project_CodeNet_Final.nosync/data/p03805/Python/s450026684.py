import itertools
import sys

N, M = map(int,input().split())

if M < N-1:
  print(0)
  sys.exit()

p = [i for i in range(N)] #点の数
root = []
for i in range(M):
  a,b = map(int,input().split())
  root.append((a-1,b-1))

#たどる点の順番の全探索
pattern = list(itertools.permutations(p))
#print(pattern)

ans = 0
for i in range(len(pattern)):
  if pattern[i][0] != 0:
    break
  Flag = True
  for j in range(N-1):
    if (pattern[i][j], pattern[i][j+1]) in root:
      continue
    elif (pattern[i][j+1], pattern[i][j]) in root:
      continue
    else:
      Flag = False
      break
  if Flag:
    ans += 1
print(ans)      