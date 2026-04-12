N,X = list(map(int,input().split()))

#[total,パティ数]
burger = [[1]*2 for i in range(51)]

ans = 0
for i in range(1,51):
    burger[i][0] = burger[i-1][0]*2+3
    burger[i][1] = burger[i-1][1]*2+1

    if X <= burger[i][0]:
        if i < N:
            X -= N-i
        while 0<X:
            X -= 1 #一番下のBを食う
            if X==0:
                break
            
            #中間まで食べられるかどうか
            if burger[i-1][0]<=X:
                X -= burger[i-1][0]
                ans += burger[i-1][1]

                if 0<X: #中間のPを食う
                    X -= 1
                    ans += 1
                else:
                    break
            
            #中間まで食べた後はL-1バーガー+B...Bが残る
            #中間まで食べられない場合はL-1バーガーのみ残ると考えて良い
            i -= 1
            if i == 0:
                if 0<X:
                    ans += 1
                #残りはパンだけor最初からなかったのと同じ
                break
        print(ans)
        break


        