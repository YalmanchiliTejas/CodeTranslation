l = input().split(' ')
a,b,c,x,y = int(l[0]),int(l[1]),int(l[2]),int(l[3]),int(l[4])

place = []
place.append( a * x + b * y )

if x-y > 0:
    place.append(c * x * 2)
else:
    place.append(c * y * 2)

if x < y :
    place.append(c * x * 2 + b * (y-x))
else :
    place.append(c * y * 2 + a * (x-y))
    
print(sorted(place)[0])
