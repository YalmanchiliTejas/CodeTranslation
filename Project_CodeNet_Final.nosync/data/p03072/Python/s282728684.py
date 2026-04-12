import numpy as np

N = int(input())
H_list = list(map(int,input().split()))[::-1]

cnt = 0
for i in range(N):
  temp_H_list = H_list[i:]
#  print(temp_H_list)
  if np.argmax(temp_H_list)==0:
    cnt+=1
    
print(cnt)