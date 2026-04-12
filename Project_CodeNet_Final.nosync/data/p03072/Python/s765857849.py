N = int(input())
H = list(map(int,input().split()))

max_h = 0
total = 0
for h in H:
  if h >= max_h:
    total += 1
    max_h = h
  else:
    continue
    
print(total)