a,b,ab,x,y=map(int,input().split())
if(a<b):
    mymax=[b,y]
    mymin=[a,x]
else:
    mymax=[a,x]
    mymin=[b,y]


if( 2*ab <= mymin[0]):
    print( 2*ab*max([x,y]) )
elif(2*ab <=mymax[0]):
    if(max([x,y]) ==mymax[1]):
        nedan=ab*2*mymax[1]
    else:
        nedan=ab*2*min([x,y]) + (mymin[1]-mymax[1])*mymin[0]
    print(nedan)
elif(2*ab <=a+b):
    if(mymax[1]==max([x,y])):
        print(2*ab*mymin[1] + mymax[0]*(mymax[1]-mymin[1]))
    else:
        print(2*ab*mymax[1] + mymin[0]*(mymin[1] - mymax[1]) )
else:
    print(a*x+b*y)