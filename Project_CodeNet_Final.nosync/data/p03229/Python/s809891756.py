n = int(input())
a = [int(input()) for _ in range(n)]
a.sort(reverse=True)

if n % 2 == 0:
    a_l = a[: n//2]
    a_s = a[n//2:]
    print((2 * sum(a_l) - min(a_l)) - (2 * sum(a_s) - max(a_s)))

else:
    x = 2 * sum(a[:(n-1)//2-1]) + sum(a[(n-1)//2-1:(n-1)//2+1]) - 2 * sum(a[(n-1)//2+1:])
    y = 2 * sum(a[:(n-1)//2]) - sum(a[(n-1)//2:(n-1)//2+2]) - 2 * sum(a[(n-1)//2+2:])
    print(max(x, y))