import sys
A, B, C, X, Y = map(int, input().split())

answer = sys.maxsize
for i in range(max(X, Y)+1):
  total = i*2*C+A*max(0,X-i)+B*max(0,Y-i)
  answer = min(answer, total)
print(answer)