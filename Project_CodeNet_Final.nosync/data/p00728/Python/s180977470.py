p=1
num=[]
while p==1:
    x=int(input())
    if x==0:
        break
    else:
        y=x
        while y>0:
            a=int(input())
            num.append(a)
            y-=1
        num.sort()
        del num[0]
        del num[-1]
        poo=sum(num)
        pooh=poo//(x-2)
        print(pooh)
        num.clear()
