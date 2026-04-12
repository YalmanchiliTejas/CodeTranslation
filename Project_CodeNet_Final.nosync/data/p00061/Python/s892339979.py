def answer():
    point={}
    number=[]
    number_n=[]
    while 1:
        N=list(map(int,input().split(",")))
        if N==[0,0]:break
        number.append(N)
        number_n.append(N[1])
    number_n=sorted(number_n)[::-1]
    count=1
    co=number_n[0]
    for i in number_n:
        if i in point:continue
        elif i<co:
            count +=1
            co=i
            point[co]=count
        else:point[i]=count
    data={}
    for j in number:
        if j[1] in point:data[j[0]]=point[j[1]]
    return data

ans=answer()
while 1:
    try:print(ans[int(input())])
    except:break
