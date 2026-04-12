while 1:
    n=int(input())
    if n==0:break
    a=[int(input()),1]
    for i in range(n-1):
        b=int(input())
        if a[-2]==b:a[-1]+=1
        if i&1 and a[-2]!=b:a+=[b]+[1]
        elif a[-2]!=b:
            if len(a)>2:
                a[-3]+=a[-1]+1
                a=a[:-2]
            else:
                a[-2]=b
                a[-1]+=1
    print(sum(a[2*i+1] for i,x in enumerate(a[::2])if x==0))