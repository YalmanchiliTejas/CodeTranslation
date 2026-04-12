N = int(input())
A = list(map(int, input().split()))
t = 1
for i in range(1, N):
  s = 0
  for j in range(i):
    if A[i] < A[j]:
      s = 1
  if s == 0:
    t += 1
    
print(t)