a,b,c,x,y = map(int,input().split())


A = 0
B = 0
res = 0

if c*2 <= a+b:
    res += min(x,y)*2*c
    A = min(x,y)
    B = min(x,y)

if x > A:
    res += (x-A)*min(2*c,a)
if y > B:
    res += (y-B)*min(2*c,b) 
print(res)
