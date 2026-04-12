import math
N = int(input())
l = len(str(N))
K = int(input())
def calc(a, b, c):
    t = 0
    if a-b-1>=0:
        t = (math.factorial(a-1) // (math.factorial(a-b-1) * math.factorial(b)))*(9**(b))
    if b==1:
        t2 = int(str(c)[0])
    else:
        t2 = (math.factorial(a-1) // (math.factorial(a-b) * math.factorial(b-1)))*(9**(b-1))*(int(str(c)[0])-1)
    t3 = 0
    try:
        n = int(str(c)[1:])
        if 2<=b<=len(str(n))+1:
            t3 = calc(len(str(n)), b-1, n)
    except:
        pass
    return t+t2+t3

if l>=K:
    print(calc(l, K, N))
else:
    print(0)