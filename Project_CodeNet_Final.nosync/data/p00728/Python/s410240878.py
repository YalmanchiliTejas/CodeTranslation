while 1:
    n = int(input())
    if n == 0:
        break
    a = []
    for i in range(n):
        a.append(int(input()))
    print((sum(a)-max(a)-min(a))//(n-2))

