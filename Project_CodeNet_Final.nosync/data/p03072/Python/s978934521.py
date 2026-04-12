
n = int(input())
h = list(map(int, input().split()))


max_h = [0]*n
max_h[0]=h[0]
for i in range(1,n):
  max_h[i] = max(max_h[i-1],h[i])

count=1
for i in range(1,n):
  if max_h[i-1]<=h[i]:
    count+=1
    

print(count)