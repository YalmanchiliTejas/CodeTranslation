while(1):
    num=int(raw_input())
    if num==0:
        break
    else:
        d=[0,1,2,3,4,5,6]
        sum=1
        for i in range(num):
            dir=num=raw_input()
            if dir=="North":
                d=[0,d[2],d[6],d[3],d[4],d[1],d[5]]
            elif dir=="East":
                d=[0,d[4],d[2],d[1],d[6],d[5],d[3]]
            elif dir=="West":
                d=[0,d[3],d[2],d[6],d[1],d[5],d[4]]
            elif dir=="South":
                d=[0,d[5],d[1],d[3],d[4],d[6],d[2]]
            elif dir=="Right":
                d=[0,d[1],d[3],d[5],d[2],d[4],d[6]]
            else:
                d=[0,d[1],d[4],d[2],d[5],d[3],d[6]]
            sum=sum+d[1]
        print sum