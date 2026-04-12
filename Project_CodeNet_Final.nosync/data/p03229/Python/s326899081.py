n = int(input())
a = sorted([int(input()) for i in range(n)])

if n % 2 == 0:
    small = a[:(n//2)]
    big = a[(n//2):]
    ans = sum(big) * 2 - sum(small) * 2  - big[0] + small[-1]
    print(ans)

else:
    small = a[:(n//2)]
    big = a[(n//2):]
    ans = sum(big) * 2 - sum(small) * 2  - big[0] -big[1]

    small = a[:(n//2)+1]
    big = a[(n//2)+1:]
    ans = max(ans, sum(big) * 2 - sum(small) * 2 + small[-1] + small[-2])
    print(ans)
