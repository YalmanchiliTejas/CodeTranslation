while True:
        a = int(input())
        if a == 0:
                break
         
        b = [int(input()) for i in range(a)]
        b.sort()
        bmin = min(b)
        bmax = max(b)
        bsum = sum(b)
        print((bsum-bmin-bmax)//(a-2))
