a,b,c,x,y = map(int,input().split())
if x >y:
    mini = [b,y]
    maxi = [a,x]
else:
    maxi = [b,y]
    mini = [a,x]

cost = 0
if a+b > 2*c:
    cost += c*mini[1]*2
    dif = maxi[1]-mini[1]
    if dif*maxi[0] > c*2*dif:
        cost += c*2*dif
    else:
        cost += dif * maxi[0]
else :
    cost += mini[0]*mini[1] + maxi[0]*maxi[1]

print(cost)