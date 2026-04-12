a,b,c,x,y=[int(i) for i in input().split()]

#直接買ったほうが安いとき

if a+b<c*2:
    print(a*x+b*y)
    
#AピザよりもABピザ２枚のほうが安い
elif a+b>=c*2:
    if x-y>0 and a<=2*c:
        print(2*c*y+(x-y)*a)
    elif y-x>0 and b<=2*c:
        print(2*c*x+(y-x)*b)
    elif x-y>0:
        print(x*2*c)
    else:
        print(y*2*c)
    