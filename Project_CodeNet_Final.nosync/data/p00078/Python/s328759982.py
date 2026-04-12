while 1:
    n = int(input())
    if n == 0:
        break
    l = [[ 0 for i in range(n)] for j in range(n)]

    i = n//2 + 1
    j = n//2
    l[i][j] = '   1'
    c = 2
    d = '{: >4}'.format(c)


    for x in range(n**2 - 1):
        i = (i + 1) % n
        j = (j + 1) % n
        while l[i][j] != 0:
            i = (i + 1) % n
            j = (j - 1) % n
        l[i][j] = d
        c += 1
        d = '{: >4}'.format(c)

    for s in range(n):
        print(*l[s],sep="")

