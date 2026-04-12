N = input()
H = list(map(int,input().split()))
count = 0
max = 0
for h in H:
  if max<=h:
    count+=1
    max=h
    
print(count)