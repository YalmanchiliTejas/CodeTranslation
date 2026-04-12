a,b,c,x,y=map(int,input().split())
cost=[]
cm=0
while cm<=2*max(x,y):
    am=x-cm//2    
    bm=y-cm//2
    if am>=0 and bm>=0: cost.append(am*a+bm*b+cm*c)
    elif am>=0 and bm<=0: cost.append(am*a+cm*c)
    elif am<=0 and bm>=0: cost.append(bm*b+cm*c)
    elif am<=0 and bm<=0: cost.append(cm*c)
    cm+=2
print(min(cost))