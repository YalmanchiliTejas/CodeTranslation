n=int(input())
K=int(input())
if K==1:
    counter=0
    for i in range(100):
        for j in range(1,10):
            a="0"*(i)+str(j)+"0"*(99-i)
            if 1<=int(a)<=n:
                counter+=1
    print(counter)
elif K==2:
    counter=0
    for i in range(100):
        for j in range(i+1,100):
            for k in range(1,10):
                for l in range(1,10):
                    a="0"*(i)+str(k)+"0"*(j-i-1)+str(l)+"0"*(99-j)
                    if 1<=int(a)<=n:
                        counter+=1
    print(counter)
elif K==3:
    counter=0
    for i in range(100):
        if 100-i>len(str(n)):
            pass
        elif 100-i<len(str(n)):
            for j in range(i+1,100):
                for k in range(j+1,100):
                    counter+=9*9*9
        elif 100-i==len(str(n)):
            for j in range(i+1,100):
                for k in range(j+1,100):

                        for b in range(1,10):
                            for c in range(1,10):
                                P=(str(n)[0])+"0"*(j-i-1)+str(b)+"0"*(k-j-1)+str(c)+"0"*(99-k)
                                if 1<=int(P)<=n:
                                    counter+=1
            counter+=((98-i)*(99-i)//2)*9*9*(int(str(n)[0])-1)
    print(counter)
                    


                    
