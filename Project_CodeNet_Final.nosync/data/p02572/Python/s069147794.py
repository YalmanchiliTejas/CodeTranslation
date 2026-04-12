M = 10**9+7

def factorial(n):
    f = 1
    for i in range(1,n+1):
        f = f*i%M
    return f

def comb(n,k):
    if n==0 or k == 0:
        return 1
    if n<k:
        return 0

    return perm(n,k)*inverse(factorial(k))%M

def mcomb(n,k):
    return comb(n+k-1,k)

def perm(n,k):
    if n==0 or k == 0:
        return 1
    if n<k:
        return 0

    p = 1
    for i in range(n-k+1,n+1):
        p = p*i%M

    return p

def inverse(a):
    return pow(a,M-2,M)

def main():
    n = int(input())
    a = tuple([int(t)for t in input().split()])

    s = sum(a)

    ans = 0

    for a_i in a:
        ans += s*a_i
        ans -= a_i**2

        ans %= M

    ans *= inverse(2)

    ans %= M

    print(ans)
    
    
if __name__ == "__main__":
    main()