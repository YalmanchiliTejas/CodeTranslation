a,b,c,x,y=map(int,input().split())
lo=0 
hi=10**19
def check(mi): 
    m=max(x,y)
    if m*2*c<=mi:
        #print('sdfu')
        return 1 
    if a<c and b<c: 
        cost=a*x+b*y 
        #print('hf')
        return cost<=mi 
    if a>c and b>c:
        cost=0 
        mini=min(x,y)
        #print('hsdfiu')
        return mini*c*2+(-mini+x)*a+(-mini+y)*b<=mi 

    if a*x+b*y<=mi:
        return 1 
    mini=min(x,y)
    if mini*c*2+(x-mini)*a+(y-mini)*b<=mi:
      #  print('sf')
        return 1 
    return 0 
#print(check(1700))
#print(check(4700))
#print(check(100000000))
while lo<=hi:
    mi=(lo+hi)>>1 
    if check(mi):
        ans=mi 
        hi=mi-1 
    else:
        lo=mi+1 
print(ans)