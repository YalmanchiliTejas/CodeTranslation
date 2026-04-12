a,b,c,x,y = map(int,input().split())

atob = x*a + y*b

maxab = (max(x,y) * 2) * c

if x > y:
    minab = y*c*2 + (x-y)*a
else:
    minab = x*c*2 + (y-x)*b
    
print(min(atob,maxab,minab))