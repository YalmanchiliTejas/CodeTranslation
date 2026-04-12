[a,b,c,x,y]=[int(i) for i in input().split()]

ansa=0
ansb=0
ansc=0

f=0
ff=0

if c*2 < a+b:
    #print("c安い")
    ansc=min(x,y)
    f=1
else:
    #print("c高い")
    ansa=x
    ansb=y

if f:
    #print(ansa, ansb, ansc)
    #print(c*2, a, x-ansc, b,  y-ansc, ansc)
    if c*2<a and x-ansc > 0:
        ansc+=x-ansc
        ff=1
        #print("aa")
    if c*2<b and y-ansc >0:
        ansc+=y-ansc
        ff=1
        #print("bb")
    if ff==0:
        ansa+=x-ansc
        ansb+=y-ansc
    

#print(ansa, ansb, ansc)
print(a*ansa + b*ansb + c*ansc*2)

