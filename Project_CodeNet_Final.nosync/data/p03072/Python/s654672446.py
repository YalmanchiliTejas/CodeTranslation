num=int(input()) 
montains=list(map(int,input().split()))

front=0
max=0
ans = 0
for high in montains:
  if high >= max:
    max = high
    if high >= front:
      ans +=1
  front=high

print(ans)