#### import ####
import sys
sys.setrecursionlimit(10**7)
import math
from collections import defaultdict

#### 定数 ####
mod = 10**9 + 7

#### 読み込み ####
def I(): return int(input())
def II(): return map(int, input().split())
def III(): return list(map(int, input().split()))
def Line(N):
  read_all = [tuple(map(int, input().split())) for _ in range(N)]
  return map(list,zip(*read_all))

#################

from collections import deque

N = I()
tempA = [0]*N
for i in range(N):
  tempA[i] = I()
  
tempA.sort()
A = deque(maxlen=N)
for i in range(N):
  A.append(tempA[i])
A2 = tempA[:]


temp = A.popleft()
B = deque(maxlen=N)
B.append(temp)
for i in range(math.ceil((N-1)/2)):
  if i%2==0:
    temp = A.pop()
    B.appendleft(temp)
    if len(A)>0:
      temp = A.popleft()
      B.appendleft(temp)
  else:
    temp = A.pop()
    B.append(temp)
    if len(A)>0:
      temp = A.popleft()
      B.append(temp)

val1 = 0
val2 = val1
for i in range(N-1):
  val1 += abs(B[i]-B[i+1])

if N%2==1:
  val2 = val1-abs(A2[(N-1)//2]-A2[(N-1)//2+1])+abs(A2[(N-1)//2]-A2[(N-1)//2-1])
print(max(val1,val2))