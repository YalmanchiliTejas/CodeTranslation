while True:
    b=[]
    a,c,ans,f,g=0,0,0,0,0
    try:
        for i in range(5):
            f,g=map(int,input().split())
            if f==0 and g==0:
                break
            a=f+g
            b.append(a)
        if a==0 and b==0:
            break
        c=max(b)
        if c==b[0]:
            ans="A"
        if c==b[1]:
            ans="B"
        if c==b[2]:
            ans="C"
        if c==b[3]:
            ans="D"
        if c==b[4]:
            ans="E"
        print(ans,c)
    except:break
