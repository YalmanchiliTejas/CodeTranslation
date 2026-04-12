n = input()
h = list(map(int,input().split()))

total = 0
maxN = 0
for num in h:
  if  num >= maxN:
    total += 1
  
  maxN = max(maxN,num)

print(total)
