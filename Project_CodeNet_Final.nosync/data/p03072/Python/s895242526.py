n =int(input())
h = list(map(int, input().split()))

high = 0
cnt = 0

for i in range(n):
  if high <= h[i]:
      high = h[i]
      cnt +=1
print(cnt)