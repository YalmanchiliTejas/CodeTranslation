n = int(input())
a = list(map(int, input().split()))

if(len(a)%2 == 0):
    b = a[1::2][::-1]+a[0::2]
    print(' '.join(map(str, b)))
else:
    b = a[0::2][::-1]+a[1::2]
    print(' '.join(map(str, b)))