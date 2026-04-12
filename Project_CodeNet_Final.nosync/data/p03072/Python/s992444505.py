n = int(input())
h = list(map(int,input().split()))

count = 1
for i in range(1,n):
  subh = sorted(h[0:i+1])
  if h[i]==subh[-1]:
    count += 1
print(count)