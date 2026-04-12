N = int(input())
H = list(map(int, input().split()))

i=0
m=0

for h in H:
  if(h>=m):
    i=i+1
    m=h
    
print(i)