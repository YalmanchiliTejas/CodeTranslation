a,b,c,x,y = map(int,input().split())

chp = min(a+b,c*2)
memo1 = min(x,y)
memo2 = max(x,y)-min(x,y)
if x>y:
    a = min(a,c*2)
    print(memo2*a+memo1*chp)
else:
    b = min(b,c*2)
    print(memo2*b+memo1*chp)