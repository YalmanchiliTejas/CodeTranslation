x,y,z = map(int,input().split())
isu = z
count = 0
while isu<=x-z:
    if isu+y<=x-z:
        isu += y
        isu += z
        count += 1
    else:
        break
print(count)