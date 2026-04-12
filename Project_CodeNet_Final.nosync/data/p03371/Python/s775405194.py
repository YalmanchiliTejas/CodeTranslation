def cc095():
    a,b,c,x,y = list(map(int, input().split()))

    prs = [a*x + b*y] # ストレートに購入
    # aを基準にc
    ac = x*2*c
    if y > x:
        z = y - x
        ac += min([b*z, z*2*c])
    prs.append(ac)

    # bを基準にc
    bc = y*2*c
    if x > y:
        z = x - y
        bc += min([a*z, z*2*c])
    prs.append(bc)

    print(min(prs))

cc095()
