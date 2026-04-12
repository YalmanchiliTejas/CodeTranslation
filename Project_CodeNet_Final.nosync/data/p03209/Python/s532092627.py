def count(n,x):
    n_1_element = 2**(n+1)-3
    if x == 0:
        return 0
    if n == 0:
        return 1
    if (x <= n_1_element+1):
        return count(n-1,x-1)
    else:
        return 2**n + count(n-1,x-n_1_element-2)

N, X = map(int,input().split())
a = count(N,X)
print(a)