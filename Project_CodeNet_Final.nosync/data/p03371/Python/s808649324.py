def makeAccount():
    fee=0
    a,b,c,x,y=map(int,input().split())

    #まずはA,Bどちらかが0になるまで購入
    fee+=min(x,y)*min(a+b,2*c)
    x, y=x-min(x,y), y-min(x,y)

    #残りのAを購入
    fee+=x*min(a, 2*c)

    #残りのBを購入
    fee+=y*min(b, 2*c)

    return fee
    
print(makeAccount())
