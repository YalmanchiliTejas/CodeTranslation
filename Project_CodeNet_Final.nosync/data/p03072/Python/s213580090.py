n = int(input())
a = list(map(int,input().split()))
r = min(a)
count = 0
for i in range(n):
  if(r <= a[i]):
    count += 1
    r = a[i]
print(count)