while True:
    a1, a2 = map(int, input().split())
    if a1 == 0:
        break
    ans = 'A'
    maxi = a1+a2
    for i in range(1,5):
        x1, x2 = map(int, input().split())
        if x1+x2 > maxi:
            maxi = x1+x2
            ans = chr(ord('A')+i)
    print(ans,maxi)

