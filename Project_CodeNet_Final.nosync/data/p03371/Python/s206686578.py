a,b,c,x,y = map(int,input().split())
minprice = 10 ** 12
for i in range(max(x,y)+1):
         if ((2*c*i)+(max(x-i,0)*a)+(max(y-i,0)*b)) < minprice:
                  minprice = ((2*c*i)+(max(x-i,0)*a)+(max(y-i,0)*b))
print(minprice)
