if __name__ == '__main__':
    h, w = map(int, input().split())
    map=[]
    for i in range(h):
        a=input()
        map.append(a)
    checkH=[False]*h
    checkW=[False]*w

    for i in range(h):
        for j in range(w):
            if map[i][j] =="#":
                checkH[i]=True
                checkW[j] = True

    for i in range(h):
        ans=""
        for j in range(w):
            if checkH[i] ==True and checkW[j]==True:
                ans+=map[i][j]
        if ans != "":
            print(ans)