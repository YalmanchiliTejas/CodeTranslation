n=int(input())
x=0;y=0
for i in range(1,n+1):
  x+=800
for m in range(1,n+1):
  if m % 15 == 0:
    y += 200

print(x-y)
  