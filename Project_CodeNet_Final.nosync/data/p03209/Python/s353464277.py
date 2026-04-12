N,X = map(int,input().split())

a,p = [1], [1] #総枚数a,パティの枚数がp
for i in range(N): #a[i] = iバーガーの枚数
    a.append(a[i] *2 +3)
    p.append(p[i] *2 +1)

def f(N,X):
    if N == 0:
        if X>0:
            return 1
        else:
            return 0
        
    elif X <= 1 + a[N-1]:#真ん中以下の場合
        return f(N-1,X-1)#N-1バーガーでX-1（バンズがふえているので）枚食べるのと同じ
    else:
        return p[N-1] +1 + f(N-1, X-2-a[N-1])#N-1バーガー+真ん中パティ+N-1バーガーのうち[X-2-N-1バーガーの枚数]分だけ食べる
print(f(N,X))