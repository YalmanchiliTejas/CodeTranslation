import math

N = int(input())
H = list(map(int, input().split()))

view = 1
for i in range(N-1):
  if H[i+1]>=sorted(H[:i+1])[-1]:
    view = view+1
  else:
    continue
print(view)