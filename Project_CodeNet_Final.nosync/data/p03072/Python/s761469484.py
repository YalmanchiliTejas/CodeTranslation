N = int(input())
h = list(map(int,input().split()))
count = 0
for i in range(0,N):
  if h[i] >= max(h[0:1+i]):
    count +=1
print(count)