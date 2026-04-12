from operator import mul
from functools import reduce
def cmb(n,r):
    r = min(n-r,r)
    if r == 0: return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1,r + 1))
    return over // under

n = int(input())
k = int(input())

result = 0
for i in range(101):
    if n < 10 ** i:
        if i < k:
            break
        if i > k:
            result += cmb(i-1, k) * 9**k
        s = str(n)
        result += (int(s[0])-1) * cmb(i-1, k-1) * (9 **(k-1))
        if k > 1:
            ind = -1
            for j in range(1, i):
                if s[j] != '0':
                    ind = j
                    break
            if ind == -1:
                break
            if i - ind >= k:
                result += cmb(i-ind-1, k-1) * (9**(k-1))
            result += (int(s[ind])-1) * cmb(i-ind-1, k-2) * (9**(k-2))
            if k > 2:
                ind2 = -1
                for j in range(ind+1, i):
                    if s[j] != '0':
                        ind2 = j
                        break
                if ind2 == -1:
                    break
                result += (i-ind2-1) * 9 + int(s[ind2])
            else:
                result+=1
        else:
            result+=1
        break
print(result)