x,y,z = map(int,input().split())

n = int(x/(y+z))
res = 0
total = 0
for i in range(n):
    if i  ==  0:
        total += z*2+y
    else:
        total += z+y
    if total <= x:
        res += 1
    else:
        break
print(res)