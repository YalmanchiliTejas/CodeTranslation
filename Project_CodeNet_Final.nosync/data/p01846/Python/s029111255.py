
while True:
     
    Y = input().split("/")
    if Y[0] == "#":
        break
    L = [[False for i in range(9)]for i in range(9)]

    MX = 1
    MY = len(Y)

    for i in range(len(Y)):
        p = 0
        for str_ in Y[i]:
            #print(i,str_)

            if str_ == "b":
                L[i][p] = True
                p += 1
            else:
                p += int(str_)
            MX = max(MX,p)

    #print(L)

    y1,x1,y2,x2 = map(int,input().split(" "))

    #print(y1,x1,y2,x2)

    L[y1-1][x1-1] = False
    L[y2-1][x2-1] = True

    #print(L)

    #print(MX,MY)

    ans = ""
    f = False

    for y in range(MY):
        ans_ = ""
        cnt = 0
        for x in range(MX):
            if L[y][x]:#b
                if cnt > 0:
                    ans_ += str(cnt)
                ans_ += "b"
                cnt = 0
            else:#
                cnt += 1
        if cnt > 0:
            ans_ += str(cnt)
        if y != MY-1:
            ans_ += "/"
        ans += ans_
    print(ans)

