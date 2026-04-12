while True:
    n=int(input())
    x=[]
    for i in range(n):
        a=int(input())
        x.append(a)
        i+=1
    if n==0:
        break
    x.sort()
    sum=0
    l=len(x)
    for i in range(1,l-1):
        sum+=x[i]
    y=sum//(l-2)
    print(y)

