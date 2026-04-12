x=[]
while True:
    n=int(input())
    if n==0:
        break
    else:
        for i in range(n):
            s=int(input())
            x.append(s)
        S1=sum(x)-max(x)-min(x)
        S2=n-2
        print(int(S1/S2))
        x.clear()
