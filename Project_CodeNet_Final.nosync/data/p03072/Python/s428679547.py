n = int(input())
l = list(map(int,input().split()))

left = l[0]
count = 1
for i in range(1,n):
  if l[i] >= left:
    count += 1
    left = l[i]
print(count)