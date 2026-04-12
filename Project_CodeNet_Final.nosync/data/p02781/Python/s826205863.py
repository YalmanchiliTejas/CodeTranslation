import math as m

n = int(input())
k = int(input())

def f(n,k):
    l = len(str(n))
    if l < k:
        ans = 0
    elif k == 0:
        ans = 1
    elif l == k:
        t = 10 ** (k-1)
        ans = (n//t-1) * f(t-1, k-1) + f(n%t,k-1)
    else:
        ans =  m.factorial(l-1) // m.factorial(k) // m.factorial(l-1-k) * (9 ** k)
        t = n % (10**(l-1))
        ans += f(t,k-1) + f(10**(l-1)-1,k-1)* (n// (10**(l-1))-1)
    return ans

ans = f(n,k)

print(ans)