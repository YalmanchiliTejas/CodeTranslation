a,b,c,x,y=map(int,input().split())
hand=[]
hand.append(x*a+y*b)
if x>y:
    hand.append(y*c*2+(x-y)*a)
    hand.append(x*c*2)
elif x==y:
    hand.append(x*c*2)
else:
    hand.append(x*c*2+(y-x)*b)
    hand.append(y*c*2)
print(min(hand))