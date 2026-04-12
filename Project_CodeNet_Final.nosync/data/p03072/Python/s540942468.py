n = int(input())
h = list(map(int,input().split()))
sum = 1
for i in range(1,n):
  if max(h[:i])<=h[i]:
     sum+=1
print(sum)