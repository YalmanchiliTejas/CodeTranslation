N = int(input())
high = list(map(int,input().split()))
count = 0
a = []

for i in range(1,N):
  a=[]
  for j in range(i):
    if high[i]-high[j]>=0:
      a.append(high[j])
  else:
    if len(a) == i:
      count += 1

print(count+1)  
