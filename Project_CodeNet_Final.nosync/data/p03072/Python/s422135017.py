n = int(input())
h = [int(item) for item in input().split()]
 
c = 0 #count
 
for i in range(n):
  flag=0
  if i==0:
    pass
  else:
    for j in range(i):
      if h[j] > h[i]:
        flag=1
        break
  if flag == 0:
    c+=1
print(c)