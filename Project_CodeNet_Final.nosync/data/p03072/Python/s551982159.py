import numpy as np

n = int(input())
a = input().split()
a = list(map(int,a))

#d = np.diff(np.array(a))
#print(d)
count =0
x = 0
#for i in d:
#  if i > 0:
#    count+=1
#print(count+1)    
for i in a:
  if x <= i:
    x = max(x,i)
    count +=1
    
print(count) 