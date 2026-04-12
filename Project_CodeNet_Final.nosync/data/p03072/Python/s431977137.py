N=int(input())
L=[int(x) for x in input().split()]
mx=0
r=0
for i in range(N):
   if L[i]>=mx:
       r+=1
       mx=L[i]

print(r)
       
