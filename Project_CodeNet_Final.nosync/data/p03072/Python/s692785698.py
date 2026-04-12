n = int(input())
hs = list(map(int,input().split()))
count = 1
for i in range(1,n):
  target = hs[i]
  if max(hs[0:i+1]) == target:
    count += 1
print(count)