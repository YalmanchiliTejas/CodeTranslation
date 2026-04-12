N = int(input())
a = []
a = list(map(int, input().split()))
h=a[0]
t=0
for i in range(N):
  if a[i]>=h:
    t+=1
    h=a[i]
print(t)