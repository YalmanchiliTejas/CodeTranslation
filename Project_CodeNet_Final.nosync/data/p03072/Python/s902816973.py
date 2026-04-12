import sys
 
n=int(input())
h=input().split()
count=0
max=int(h[0])
for i in range(n):
  if int(h[i])>=max:
    max=int(h[i])
    count+=1
print(count)