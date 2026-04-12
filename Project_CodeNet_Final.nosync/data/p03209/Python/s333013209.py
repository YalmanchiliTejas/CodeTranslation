n,x = map(int,input().split())

a,p = [1],[1] #a:all,p:pate
for i in range(n):
    a.append(a[i]*2+3)
    p.append(p[i]*2+1)

def func(n,x): #n:バーガーの次元、x:下から何層か
    if n == 0: #終了条件：0次元まで逆算で戻る
        if x <= 0: #0次元の時、一応パテは1枚あるので、xが1余ってる場合を考慮
            return 0
        else:
            return 1
    elif x <= 1 + a[n-1]: #xがその次元の枚数より少ないなら
        return func(n-1,x-1)
    else:
        return p[n-1]+1+func(n-1,x-2-a[n-1])

print(func(n,x))