from collections import deque
N = int(input())
H = []
Q = deque()
for i in range(N):
  A = int(input())
  H.append(A)
H.sort()
#H = deque(H)

if N%2 == 0:
  groupA = H[:N//2]
  groupB = H[N//2:]
  ans = 2*sum(groupB)-2*sum(groupA)-groupB[0]+groupA[-1]
else:
  groupA1 = H[:N//2]
  groupB1 = H[N//2:]
  groupA2 = H[:N//2+1]
  groupB2 = H[N//2+1:]
  ans1 = 2*sum(groupB1)-2*sum(groupA1)-groupB1[0]-groupB1[1]
  ans2 = 2*sum(groupB2)-2*sum(groupA2)+groupA2[-1]+groupA2[-2]
  ans = max(ans1,ans2)
print(ans)