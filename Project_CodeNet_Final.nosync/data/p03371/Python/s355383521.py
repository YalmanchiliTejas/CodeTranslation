a,b,c,x,y = map(int,input().split())
print( min( max(x,y)*2*c , x*a+y*b , max(2*c*min(x,y)+(x-min(x,y))*a, 2*c*min(x,y)+(y-min(x,y))*b)  ) )


