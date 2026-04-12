while True:
    n=int(input())
    if n==0:
        break
    x=[]
    for i in range(n):
        a=int(input())
        x.append(a)
    y=sorted(x)
    sum=0
    for j in range(1,len(y)-1):
        sum+=y[j]
    ave=sum//((len(y))-2)
    print(ave)
