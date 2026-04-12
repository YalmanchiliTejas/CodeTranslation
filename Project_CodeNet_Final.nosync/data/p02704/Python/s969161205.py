
"""

https://atcoder.jp/contests/abc164/tasks/abc164_f

各桁ごとに考えればよい
1.論理積が0 → 1つでも0があればおｋ → 0
2.論理積が1 → 全て1
2.論理和が0 → 全て0
1.論理和が1 → 1つでも1があればおk → 1

つまり、論路積が0,論理和が1を満たすような並べ方を見つければいい
そのような行・列が2つ以上ある場合は、01で市松模様で塗る
1つしかない場合、1でない方を見て行って、塗らなきゃいけない所だけ塗る
後は1つの方を見て行って、塗る

"""

from sys import stdin
import sys

N = int(stdin.readline())
S = list(map(int,stdin.readline().split()))
T = list(map(int,stdin.readline().split()))
U = list(map(int,stdin.readline().split()))
V = list(map(int,stdin.readline().split()))

ans = [[0] * N for i in range(N)]

for dig in range(64):
    nd = 2**dig

    a = [[None] * N for i in range(N)]

    #まず、論理積が0 / 論理和が1を処理する

    h = [] #横でグループ2に属する
    w = [] #縦でグル2

    for i in range(N):
        
        if S[i] == 0 and U[i]&nd > 0:
            for j in range(N):
                if a[i][j] == 0:
                    print (-1)
                    sys.exit()
                a[i][j] = 1
        
        elif S[i] == 1 and U[i]&nd == 0:
            for j in range(N):
                if a[i][j] == 1:
                    print (-1)
                    sys.exit()
                a[i][j] = 0
        elif S[i] == 0 and U[i]&nd == 0:
            h.append((i,0))
        else:
            h.append((i,1))

    for j in range(N):

        if T[j] == 0 and V[j]&nd > 0:
            for i in range(N):
                if a[i][j] == 0:
                    print (-1)
                    sys.exit()
                a[i][j] = 1
        elif T[j] == 1 and V[j]&nd == 0:
            for i in range(N):
                if a[i][j] == 1:
                    print (-1)
                    sys.exit()
                a[i][j] = 0
        elif T[j] == 0 and V[j]&nd == 0:
            w.append((j,0))
        else:
            w.append((j,1))

    #print (a)

    #次に、h,wどちらも2以上の場合を処理する→交互に入れてけば終わり

    if len(h) > 1 and len(w) > 1:
        lside = 0
        now = 0
        for i,tmp1 in h:
            now = lside
            lside ^= 1
            for j,tmp2 in w:
                a[i][j] = now
                now ^= 1

    elif len(h) == 0 or len(w) == 0: #Noneがないので、ただしいかだけ確かめる

        for i,x in h:
            for j in range(N):
                if a[i][j] == x:
                    break
            else:
                print (-1)
                sys.exit()

        for j,x in w:
            for i in range(N):
                if a[i][j] == x:
                    break
            else:
                print (-1)
                sys.exit()

    elif len(w) == 1: #hの方を先に上手くやって、wの正当性を確かめる

        wj = w[0][0]
        
        for i,x in h:
            for j in range(N):
                if a[i][j] == x:
                    break
            else:
                a[i][wj] = x
                
        for j,x in w:
            flag = False
            for i in range(N):
                if a[i][j] == None:
                    a[i][j] = x
                if a[i][j] == x:
                    flag = True

            if not flag:
                print (-1)
                sys.exit()

    else: #wの方をうまくやってから、hの正当性を確かめる

        hi = h[0][0]

        for j,x in w:
            for i in range(N):
                if a[i][j] == x:
                    break
            else:
                a[hi][j] = x

        for i,x in h:
            flag = False
            for j in range(N):
                if a[i][j] == None:
                    a[i][j] = x
                if a[i][j] == x:
                    flag = True
            if not flag:
                print (-1)
                sys.exit()

    #print (a,h,w)
    for i in range(N):
        for j in range(N):
            ans[i][j] += nd * a[i][j]

for i in ans:
    print (*i)
        

                
                
