n = int(input())
h = list(map(int,input().split()))

highest = 0
s = 0
for i in range(n):
  if h[i]>=highest:
    s+=1
    highest=h[i]
print(s)