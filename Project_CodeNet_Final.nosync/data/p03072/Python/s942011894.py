a = int(input())
x = list(map(int,input().split()))
m = x[0]
s = 0
for i in range(1,a):
  if m <= x[i]:
    m = x[i]
    s+=1
print(s+1)
