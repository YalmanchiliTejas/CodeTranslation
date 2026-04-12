N = int(input())
a = list(map(int, input().split()))

tmp = 0
count = 0
for i in range(N):
  if tmp <= a[i]:
    count += 1
    tmp = a[i]
    
print(count)