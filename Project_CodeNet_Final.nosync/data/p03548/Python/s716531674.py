x,y,z = map(int,input().split())
count = 0
x=x-z
while(True):
    x = x - y
    x = x - z
    if x >= 0:
        count += 1
    else:
        break
print(count)