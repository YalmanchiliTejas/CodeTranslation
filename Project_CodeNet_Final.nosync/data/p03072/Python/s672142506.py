n = int(input())
h = [int(_) for _ in input().split()]
first = h[0]
cnt =1
for i in range(n-1):
  if h[i+1] >= first:
    first = h[i+1]
    cnt +=1
print(cnt)