import math
def comb(n, r):
    if n < r:
        return 0
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))
N = int(input())
K = int(input())
strN = str(N)
lenn = len(strN)
if K == 1:
    print((lenn-1)*9 + int(strN[0]))
elif K == 2:
    if lenn == 1:
        print(0)
    else:
        ans1 = 81*comb(lenn-1,2)
        ans1 += (int(strN[0])-1)*9*(lenn-1)
        for i in range(1,lenn):
            if int(strN[i]) != 0:
                ans1 += int(strN[i])
                ans1 += 9*(lenn-i-1)
                break
        print(ans1)
else:
    if lenn <= 2:
        print(0)
    else:
        ans1 = (9**3)*comb(lenn-1,3)
        ans1 += (int(strN[0])-1)*81*comb(lenn-1,2)
        for i in range(1,lenn):
            if strN[i] != '0':
                break
        strN = strN[i:]
        lenn = len(strN)
        if lenn == 1:
            ans2 = 0
        else:
            ans2 = 81*comb(lenn-1,2)
            ans2 += (int(strN[0])-1)*9*(lenn-1)
            for i in range(1,lenn):
                if int(strN[i]) != 0:
                    ans2 += int(strN[i])
                    ans2 += 9*(lenn-i-1)
                    break
        print(ans1+ans2)        