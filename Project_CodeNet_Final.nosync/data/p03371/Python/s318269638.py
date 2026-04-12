a,b,c,x,y= map(int ,input().split())
h=max(x,y)
k=min(x,y)
j=h-k
if a+b>(c*2):
        i=k*(c*2)
        if h==x:
                l=j*2*c
                print(min(l,(j*a))+i)
        else:
                l=j*2*c
                print(min(l,(j*b))+i)     
else:
        print((a*x)+(b*y))