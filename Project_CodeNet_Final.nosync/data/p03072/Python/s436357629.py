n = int(input())
l = list(map(int,input().split()))
max = l[0]
count = 0
for i in range(n):
  if l[i] >= max:
    count += 1
    max = l[i]
    
print(count)