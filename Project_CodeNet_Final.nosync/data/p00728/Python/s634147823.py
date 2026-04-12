while True:
    n=int(input())
    if n==0:
        break
    else:
        A=[]
        i=1
        while i <=n:
            a=int(input())
            A.append(a)
            i=i+1
        b=(sum(A)-max(A)-min(A))//(n-2)
        print(b)
