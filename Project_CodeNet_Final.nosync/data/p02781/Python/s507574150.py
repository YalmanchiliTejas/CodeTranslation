import math
import itertools

n = int(input())
k = int(input())

f = len(str(n))

if f < k:
    print(0)
else:
    #f-1桁以内に収まる数

    en = 1
    for i in range(k):
        en *= f-1-i

    de = math.factorial(k)


    s = en // de * pow(9, k)


    #f桁目によって絞る

    kami = int(str(n)[0])

    en = 1
    for i in range(k-1):
        en *= f-1-i

    de = math.factorial(k-1)


    s += (en // de * pow(9, k-1)) * (kami-1)


    #以下上1桁は同じ数字

    keta = list(range(f-1))
    num = list(range(1,10))

    b =  kami * pow(10, f-1)
    m = 0


    if k == 1:
        m = b
        if m <= n:
            s += 1
    else:
        for d in itertools.product(num, repeat=k-1):
            for c in itertools.combinations(keta, k-1):
                m = b
                for i in range(k-1):
                    m +=  d[i] * pow(10, c[i])
                if m <= n:
                    s += 1

    print(s)
