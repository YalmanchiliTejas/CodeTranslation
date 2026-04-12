num = int(input())
mountainList = list(map(int,input().split()))
sum = 0
max = 0

for mount in mountainList:
  if(mount >= max):
    sum += 1
  if(mount > max):
    max = mount
    
print(sum)