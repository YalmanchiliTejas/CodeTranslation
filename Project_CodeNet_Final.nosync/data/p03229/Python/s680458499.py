# 6,8,1,2,3
# 中央値である3から初めて、残りから最大→最小の繰り返しで貪欲に取る
# 3 8 1 6 2
# 最小->最大の順でやるのと両パターン試して、大きい方採用
#
# 3 1 4 1 5 9
# 1 1 3 4 5 9
# 偶数のときは、中央値も2パターン取って大きいのを採用
#
# 5 5 1
# 5 1 5

N=int(input())
A=[0] * N
for i in range(N):
  A[i] = int(input())
  
if N == 2:
  print(abs(A[0] - A[1]))
  exit(0)
  
A=sorted(A)
minA = A[0]
maxA = A[-1]

mid = 0

from collections import deque

def calc(A,first,flip):
  q = deque(A)
  ans = 0
  cur = first
  while q:
    if flip:
      a = q.popleft()
    else:
      a = q.pop()
    ans += abs(a - cur)
    cur = a
    flip^=True
  return ans

if N%2:
  # 奇数のとき
  mid = A.pop(N//2)
  ans1 = calc(A,mid,True)
  ans2 = calc(A,mid,False)
  print(max(ans1,ans2))
  
else:
  # 偶数のとき
  A2 = A.copy()
  mid1 = A.pop(N//2-1)
  ans1_1 = calc(A,mid1,True)
  ans1_2 = calc(A,mid1,False)
  
  mid2 = A2.pop(N//2)
  ans2_1 = calc(A2,mid2,True)
  ans2_2 = calc(A2,mid2,False)
  
  print(max(ans1_1,ans1_2,ans2_1,ans2_2))
