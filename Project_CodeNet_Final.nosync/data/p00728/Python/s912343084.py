while True:
    p=int(input())
    
    if p==0:
        break
    else:
        list1=[]

        for i in range(p):
            a=int(input())
            list1.append(a)
            i+=1

        min1=min(list1)
        max1=max(list1)

        list1.remove(min1)
        list1.remove(max1)

        sum1=sum(list1)

        men=p-2
        print(sum1//men)


