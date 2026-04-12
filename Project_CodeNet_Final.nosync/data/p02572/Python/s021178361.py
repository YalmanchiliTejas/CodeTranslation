n=int(input())
li = list(map(int,input().split()))

part_of_sum=[]
s=0
mini_sum=sum(li[1:])
for j in range(n-1):
  s+=li[j]*mini_sum
  mini_sum-=li[j+1]

print(s%(10**9+7))