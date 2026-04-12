n = int(input())
x = list(map(int, input().split()))
y = x[0]
a = 0
for i in range(n-1):
  if y <= x[i+1]:
    y = x[i+1]
    a+=1  
print(a+1)