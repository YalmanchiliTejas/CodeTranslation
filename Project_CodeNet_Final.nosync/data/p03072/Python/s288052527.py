N = int(input())
Hs = list(map(int,input().split()))
Max = 0
number = 0
for i in range(N):
  if Max <= Hs[i]:
    Max = Hs[i]
    number += 1
print(number)