N,X,M = map(int,input().split())
O = [0]*M

XX = X

ans = 0
a = 1
while a <= N:
    if O[X] == 0:
        O[X] = a
    else:
        b = O[X]
        c = a - b
        d = N - (N - b) % c 
        e = N - d
        h = ((N - b) // c)
        #print(*O)
        #print(b,c,d,e,h)
        ans = 0
        X = XX
        for i in range(b):
            ans += X
            X = (X * X) % M
        for i in range(c):
            if i < e:
                ans += (h + 1) * X
            else:
                ans += h * X
            X = (X * X) % M
        print(ans)
        exit()
    ans += X
    X = (X * X) % M
    a += 1

print(ans)