while 1:
    n,l,r=map(int, input().split())
    if n==0:
        break
    a = []
    for i in range(n):
        a.append(int(input()))
    c = 0
    for j in range(l, r+1):
        for i in range(n):
            if j%a[i]==0:
                if i%2==1:
                    break
                else:
                    c += 1
                    break
            if i==n-1 and n%2==0:
                c += 1
    print(c)
