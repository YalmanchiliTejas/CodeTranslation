while True:
    n=int(input())
    if n==0:
        break
    else:
        a=[int(input()) for i in range(n)]
        x=max(a)
        y=min(a)
        a.remove(x)
        a.remove(y)
        ave = sum(a)//len(a)
        print(ave)
