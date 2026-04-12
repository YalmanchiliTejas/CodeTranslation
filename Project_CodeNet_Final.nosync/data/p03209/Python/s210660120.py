n,x=map(int,input().split())
a=1
b=1
sou=[a] #各バーガーの層の数
patty=[b] #各バーガーのパティの数
for i in range(49):
    a=(3+2*a)
    b=(1+2*b)
    sou.append(a)
    patty.append(b)
zan=x
total=0 #xまでに含まれるパティの数
ok=0
def check(num): #レベルiバーガーで調べる。
    global zan,total,ok
    if ok==1:
        return
    for i in range(5):
        if i==0 or i==4:
            zan-=1
        elif i==2:
            zan-=1
            total+=1
        else:
            zan-=sou[num-1]
            total+=patty[num-1]
        if zan==0:
            ok=1
            return
        elif zan<0:
            total-=patty[num-1]
            zan+=sou[num-1]
            #print(str(num-1)+" "+str(zan))
            check(num-1)
            if ok==1:
                break
check(n)
print(total)