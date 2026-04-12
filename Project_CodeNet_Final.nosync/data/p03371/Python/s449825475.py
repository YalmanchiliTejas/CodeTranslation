a,b,ab,x,y=map(int,input().split())

if x<y:
    #print((y-x)*b+x*ab*2)
    print(min((y-x)*b+x*ab*2 , a*x+b*y , y*ab*2))
else:#x>=y
    #print((x-y)*a+y*ab*2)
    print(min((x-y)*a+y*ab*2,a*x+b*y , x*ab*2))
