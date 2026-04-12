n = int(input())
m = [int(i) for i in input().split()] 

i = 0
max_h = m[0]
count = 0

while i < n:
  if m[i] >= max_h:
    count += 1
  max_h = max(max_h, m[i])
  i += 1
  
print(count)
  
  
