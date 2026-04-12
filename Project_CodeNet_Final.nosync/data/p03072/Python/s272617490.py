x = input()
y = list(map(int,input().split()))

max_ = y[0]
point = 0
for i in y:
  
  if i >= max_:
    point += 1
    max_ = i
  
print(point)