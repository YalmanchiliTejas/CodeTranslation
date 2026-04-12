N = int(input())
lia=[int(it) for it in input().split()]
lib=[0]*N

ma = -1
s=0
for i in range(N):
  if (lia[i]>=ma):
    s+=1
  ma = max(lia[i],ma)
print (s)