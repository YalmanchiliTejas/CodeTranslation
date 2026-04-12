# coding: utf-8
N = int(input())
H = input().split()
ans = 1

for i in range(1,N):
  tmp = 0
  for j in range(i):
    if int(H[i]) < int(H[j]):
      tmp = 1
      break
  if tmp == 0:
    ans += 1
    
print(ans)