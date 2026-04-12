n = int(input())
l = list(map(int, input().strip().split()))
s = 1
mas = l[0]
for i in range(1,n):
  if l[i] >= mas:
    s+=1
    mas = l[i]
print(s)