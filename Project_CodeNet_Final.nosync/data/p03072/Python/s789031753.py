num = int(input())
mtlist = [int(x) for x in input().split()]
mtmax = 0
view = 0

for i in range(num):
  if mtlist[i] > mtmax:
    mtmax = mtlist[i]
    view = view +1
  elif mtlist[i] == mtmax:
    view = view +1
  else:
    continue
    
print(view)