from math import factorial
def comb(n,k):
    if n>=k:
        return int(factorial(n)/(factorial(k)*factorial(n-k)))
    else:
        return 0


def calc(a,k):
        t = len(a)
        t1 = len(a) - 1
        if k<1 or t == 0:
            return 0
        else:
            if a[t1]>0:
                ans = (9**k)*comb(t1,k) + (9**(k-1))*(a[t1]-1)*comb(t1,k-1)
                ans+=calc(a[:(t-1)],k-1)
            else:
                ans = 0
                ans+=calc(a[:(t-1)],k)
            if a[-k]>=1 and k == 1:
               ans+=1
            return ans


n = int(input())
k = int(input())
number = []
while n:
    number.append(n%10)
    n//=10

t = len(number)
t1 = len(number) - 1

if t>=k:
    ans = 0
    ans += calc(number,k)
else:
    ans = 0
print(ans)