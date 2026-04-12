n, k = (int(x) for x in input().split())
c = 0
if k == 0:
    print(n*n)
else:
    for i in range(k+1, n+1):
        c += (i-k)*(n//i)
        m = n%i
        if m-k+1 >= 0:
            c += m-k+1
    print(c)
