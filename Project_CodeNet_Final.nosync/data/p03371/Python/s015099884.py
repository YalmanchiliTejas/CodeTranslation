
    
a,b,c,x,y=map(int,input().split())
d=(a+b)/2
import sys
o=x
w=y
count=0
if d>=c:
    if x>=y:
        r=x
        
        x-=y
        
        count+=(y*2*c)
        count+=((r-y)*a)
        print(min(count,o*2*c))
        sys.exit()
      

    else:
        r=y
        
        y-=x
        
        count+=(x*2*c)
  
        count+=((r-x)*b)
        
        
        print(min(count,w*2*c))
        sys.exit()
    
        
else:
    count+=(a*x+b*y)    
    print(count)

    
