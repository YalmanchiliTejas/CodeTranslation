import sys
readline=sys.stdin.readline

N,X,M = map(int,readline().split())
route = [X]
dic = {}
first = []
loop = []
for i in range(1, N):
  X = (X ** 2) % M
  if X in dic:
    first = route[:dic[X]]
    loop = route[dic[X]:]
    break
  route.append(X)
  dic[X] = i
  
if len(first) == 0:
  print(sum(route[:N]))
  exit(0)

if N == len(first):
  print(sum(first))
elif N < len(first):
  print(sum(first[:N]))
else:
  ans = sum(first)
  one_loop = sum(loop)
  N -= len(first)
  loop_cnt = N // len(loop)
  rest = N % len(loop)
  ans += loop_cnt * (sum(loop))
  ans += sum(loop[:rest])

  print(ans)
