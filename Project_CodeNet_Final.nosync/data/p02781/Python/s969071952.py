from math import factorial

def combinations_count(n, r):
    return factorial(n) // (factorial(n - r) * factorial(r))

n = int(input())
k = int(input())


ans = 0

if len(str(n)) < k:
    print(0)
    exit()

def ans1(n,k):
    global ans
    m = len(str(n))
    if m-1 >= k:
        ans += combinations_count(m-1, k) * 9 ** k

    if m >= k:
        ans += (int(str(n)[0])-1) * combinations_count(m-1, k-1) * 9 ** (k-1)
        if k >= 2 and m > 1:
            ans1(int(str(n)[1:]), k-1)
        elif k == 1:
            ans += 1

ans1(n,k)

print(ans)
