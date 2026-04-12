import numpy as np
 
h,w = map(int,input().split())
a = [list(input()) for i in range(h)]

arr=[]
arr2=[]
for i in a:
  if '#' in i:
    arr.append(i)
    
ar = np.array(arr)
arT = ar.T
 
for i in arT:
  if '#' in i:
    arr2.append(i)
    
arr3 = np.array(arr2)
arr4 = arr3.T
 
arr5=arr4.tolist()

for i in range(len(arr5)):
    print("".join(arr5[i]))