while True:
    n=int(input())
    if n == 0:
        break
    a=[]
    for i in range(n):
        s=int(input())
        a.append(s)
    
    print((sum(a)-max(a)-min(a))//(n-2))
