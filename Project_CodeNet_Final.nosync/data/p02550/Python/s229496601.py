N,X,M = map(int,input().split())
from collections import deque
ans = 0
flag = [0] * (M+1)
dic = dict()
q = deque()
for i in range(N):
  if not(flag[X]):
    flag[X] = 1
    dic[X] = i
    q.append(X)
    ans += X
    X = pow(X,2,M)
  else:
    q = list(q)
    loop = q[dic[X]:]
    loop_sum = sum(loop)
    loop_l = len(loop)
    length = N-i - ((N-i)//loop_l * loop_l)
    ans += loop_sum * ((N-i)//loop_l)
    ans += sum(loop[:length])
    break
print(ans)