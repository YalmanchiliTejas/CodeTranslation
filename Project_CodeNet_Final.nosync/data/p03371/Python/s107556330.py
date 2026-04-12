a,b,c,x,y=map(int,input().split())
d=min(a+b,c*2)
print((x-y)*min(a,c*2)+y*d if x>y else (y-x)*min(b,c*2)+x*d)