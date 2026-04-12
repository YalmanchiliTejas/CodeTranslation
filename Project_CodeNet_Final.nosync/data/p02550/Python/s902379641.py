def do():
    n, x, m = map(int, input().split())
    if x == 1: # x = 1の時は強制的にn
        print(n)
        return
    #print(n,x,m)
    dat = []
    d = dict()
    dat.append(x)
    d[x] = True
    #print(x)
    issyu_total = x % m
    isloop = False

    for i in range(n-1): # 最大でもn-1回
        #print(x)
        x = x ** 2 % m
        if x == 0: # 0になったときはそのあと全部0 なので、
            print(sum(dat) % m)
            return
        if x in d:
            #print("hit" + str(i) + " " + str(x))
            isloop = True
            loopstart = dat.index(x)
            break
        dat.append(x)
        issyu_total = (issyu_total + x)
        d[x] = True

    if isloop is False:
        print(issyu_total)
        return

    import math

    res = 0
    #print("loop on")
    #print(loopstart)
    loopsum = sum(dat[loopstart:])
    looplength = len(dat) - loopstart

    res = sum(dat)
    n -= len(dat)

    fullloop = math.floor(n / looplength) # 範囲分
    res += fullloop * loopsum

    nokori = n % fullloop
    res += sum(dat[loopstart:loopstart+nokori])

    #print("loopcount={0}, issyutotal={1}, nokori={2}, fl ={3} ".format(looplength, issyu_total, nokori,fullloop))
    print(res)
    #print(492443256176507 - res)






do()

