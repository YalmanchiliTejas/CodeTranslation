n = int(input())
h = list(map(int,input().split()))
maxi = 0
count = 0
for i in range(n):
  maxi = max(maxi,h[i])
  if maxi == h[i]:
    count += 1
print(count)