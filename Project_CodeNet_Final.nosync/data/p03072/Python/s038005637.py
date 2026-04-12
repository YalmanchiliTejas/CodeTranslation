yama=int(input())
n=list(map(int,input().split()))
count=0
saidai=0
for i in range(yama):
  takasa=n[i]
  if saidai<=takasa:
    saidai=takasa
    count=count+1
print(count)
