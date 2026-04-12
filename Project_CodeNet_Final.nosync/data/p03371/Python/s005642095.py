a,b,c,x,y = list(map(int,input().split()))

d = abs(x-y)
count=0
if (a+b) >= 2*c:
    count += 2*c*min(x,y)
else:
    count += (a+b)*min(x,y)

if x>=y:
    if a >= 2*c:
        count += 2*c*d
    else:
        count += a*d
else:
    if b >= 2*c:
        count += 2*c*d
    else:
        count += b*d

print(count)