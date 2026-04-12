N, X, M = map(int, input().split())
if M==1:
  print(0)
  exit()
lis = [0]*M
lis[0] = X
check = [-1]*M
check[X] = 0
for i in range(1,M):
  lis[i] = pow(lis[i-1],2,M)
  if check[lis[i]]>=0:
    cyc = i-check[lis[i]]
    start = check[lis[i]]
    break
  check[lis[i]] = i
from itertools import groupby, accumulate, product, permutations, combinations
cum = list(accumulate(lis))
cyc_cum = cum[-1]-cum[start]
if N-1<=start+cyc:
  ans = cum[N-1]
else:
  ans = cyc_cum*((N-1-start)//cyc)+cum[(N-1-start)%cyc+start]
print(ans)