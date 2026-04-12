while True:
    a=int(input())
    if a==0:break
    x=[int(input()) for i in range(a)]
    x.sort()
    print((sum(x)-max(x)-min(x))//(a-2))
   

