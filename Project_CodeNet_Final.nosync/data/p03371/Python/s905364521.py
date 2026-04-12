a , b , c ,x , y = map(int , input().split())
c2 = c *2
na , nb ,nc = 0 , 0 ,0 
if a > c2 :
    a = c2
if b > c2 :
    b = c2

if a <= c2 and b <= c2 :
    if a + b >= c2 :
        nc = min(x,y)
        if x > y :
            na = x - y
        else :
            nb = y -x
    else :
        na = x
        nb = y
print(na*a+nb*b+nc*c2)
