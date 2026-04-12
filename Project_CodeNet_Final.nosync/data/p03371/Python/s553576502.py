a,b,c,x,y = map(int,input().split())
can = []
mini = min(x,y)
maxi = max(x,y)
can.append( c * 2 * mini + a * (x-mini) + b * (y-mini) )
can.append( c * 2 * maxi )
can.append( a * x + b * y )
print(min(can))