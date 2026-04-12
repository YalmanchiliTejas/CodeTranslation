# coding: utf-8
# Here your code !
#coding: utf-8

while True:
    l = map(int,raw_input().split())
    if l == [0,0,0,0,0]:
        break
    else:
        A = l[1]
        B = l[2]
        C = l[3]
        X = l[4]
        f = -1
        Yl = map(int,raw_input().split())
        for Y in Yl:
            while f <= 10000:
                f = f + 1
                if X == Y:
                    X = (A * X + B) % C
                    break
                X = (A * X + B) % C
        if f > 10000:
            print -1
        else:
            print f