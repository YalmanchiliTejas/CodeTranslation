n = int(input())
a = list(map(int,input().split()))

if n % 2 == 1:
    b = a[::2]
    c = a[1::2]
    b.reverse()
    d = b+c
    print(' '.join(map(str,d)))
else:
    b = a[::2]
    c = a[1::2]
    c.reverse()
    d = c+b
    print(' '.join(map(str,d)))