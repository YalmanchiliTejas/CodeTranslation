N = int(input())
a = [int(i) for i in input().split()] 
c,max = 1,a[0]

for i in range(1,N):
  if max <= a[i]:
    c += 1
    max = a[i]
print(c)