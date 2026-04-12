from collections import deque
N = int(input())
 
num = []
for i in range(N):
  num.append(int(input()))
  
num = deque(sorted(num))
ans = deque([num.popleft()])
 
for i in range(N-2):
  if i % 4 == 0:
    ans.append(num.pop())
  elif i % 4 == 1:
    ans.appendleft(num.pop())
  elif i % 4 == 2:
    ans.append(num.popleft())
  else:
    ans.appendleft(num.popleft())

answer = max(abs(num[0]-ans[0]), abs(num[0]-ans[-1]))
for i in range(len(ans)-1):
  answer += abs(ans[i] - ans[i+1])
  
print(answer)