import numpy as np

h,w = map(int,input().split())
a = [list(input()) for i in range(h)]
ans1 = []
ans2 = []

for i in a:
  if '#' in i:
    ans1.append(i)
    
gyouretu = np.array(ans1)
gyouretuT = gyouretu.T

for i in gyouretuT:
  if '#' in i:
    ans2.append(i)
    
ans = np.array(ans2)
answer = ans.T

for i in answer:
  print(''.join(i))
