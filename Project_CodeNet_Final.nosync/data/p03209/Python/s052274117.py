import sys
input = lambda: sys.stdin.readline().rstrip()

N, X = map(int, input().split())

a = [1]
p = [1]
for i in range(N):
    a.append(a[i] * 2 + 3)
    p.append(p[i] * 2 + 1)

def rec(n,x):
    if n == 0:
        return 0 if x <= 0 else 1
    #真ん中以下まで到達    
    elif x <= 1 + a[n-1]:
        #バンズが一枚増えているので,真ん中以下までしか到達してない場合はn-1からx-1食べるのと同じ
        return rec(n-1, x-1)
    #真ん中以降まで到達
    else:
        #バンズ+N-1バーガー+真ん中のパティ+N-1バーガーのうち[x-a[n-1]-2]分を食べる

        return p[n-1] + 1 + rec(n-1, x-a[n-1]-2)

print(rec(N,X))