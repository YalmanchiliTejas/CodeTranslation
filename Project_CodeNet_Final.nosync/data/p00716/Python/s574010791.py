def simple(init,year,rate,fee):
    accum=0
    for i in range(year):
        accum+=int(init*rate)
        init-=fee
    return init+accum

def compound(init,year,rate,fee):
    for i in range(year):
        init+=int(init*rate-fee)
    return init

m=input()
for i in range(m):
    init=input()
    year=input()
    n=input()
    L=[map(float,raw_input().split()) for i in range(n)]
    maxInt=0
    for data in L:
        if data[0]==0:
            maxInt=max(maxInt,simple(init,year,data[1],data[2]))
        else:
            maxInt=max(maxInt,compound(init,year,data[1],data[2]))
    print int(maxInt)