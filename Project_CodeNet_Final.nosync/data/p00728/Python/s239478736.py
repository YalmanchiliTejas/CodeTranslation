while True:
    n=int(input())
    if n == 0:
        break
    else:
        maxs=0
        mins=2000
        sums=0
        for i in range(n):
            s=int(input())
            sums=sums+s
            if s<mins:
                mins=s
            if s>maxs:
                maxs=s
        print((sums-maxs-mins)//(n-2))
