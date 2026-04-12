N=int(input())
H=list(map(int,input().split(' ')))

count=0
max_=0
for h in H:
  if h>=max_:
    count+=1
    max_=h

print(count)
