n=int(input())
h=list(map(int,input().split()))
count=0
flag=1
for i in range(n):
  if max(h[:(i+1)])==h[:(i+1)][-1]:
    count+=1
print(count)