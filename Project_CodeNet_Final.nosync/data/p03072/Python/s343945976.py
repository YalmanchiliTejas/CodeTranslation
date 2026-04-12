n = int(input())
h = list(map(int, input().split()))

count=0
s = 0
for i in range(len(h)-1):
  s = max(s,h[i])
  if s <= h[i+1]:
    count+=1
print(count+1)
