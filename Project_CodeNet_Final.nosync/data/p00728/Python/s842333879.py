n = int(input())
s = 0

while n != 0:
    a = [int(input()) for i in range(n)]
    b = sorted(a)
    for i in range(1,n-1):
        s += b[i]
    c = s//(n-2)
    print('{:.0f}'.format(c))
    n = int(input())
    s = 0
