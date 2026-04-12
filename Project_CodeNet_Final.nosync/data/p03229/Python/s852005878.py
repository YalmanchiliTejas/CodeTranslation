from collections import deque
n = int(input())
D = []
for _ in range(n):
  D.append(int(input()))
D.sort()
A = deque(D)
B = deque()
B.append(A.popleft())

maxflag = 0
while True:
  if len(A) == 0:
    break
  if len(A) == 1:
    a = A.pop()
    B.appendleft(a)
    break
  if maxflag % 2 == 0:
    a = A.pop()
    b = A.pop()
  else:
    a = A.popleft()
    b = A.popleft()
  B.appendleft(a)
  B.append(b)
  maxflag += 1
ans = 0
for i in range(len(B)-1):
  ans += abs(B[i] - B [i+1])

A = deque(D)
B = deque()
B.append(A.pop())

maxflag = 1
while True:
  if len(A) == 0:
    break
  if len(A) == 1:
    a = A.pop()
    B.appendleft(a)
    break
  if maxflag % 2 == 0:
    a = A.pop()
    b = A.pop()
  else:
    a = A.popleft()
    b = A.popleft()
  B.appendleft(a)
  B.append(b)
  maxflag += 1
ans2 = 0
for i in range(len(B)-1):
  ans2 += abs(B[i] - B [i+1])
print(max(ans, ans2)) 

