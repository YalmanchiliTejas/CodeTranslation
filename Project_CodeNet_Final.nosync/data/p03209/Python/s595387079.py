N, X = map(int,input().split())

a = [1] #i番目にはi番目に作られるハンバーガーの大きさが入っている : a[i+1] = 2 * a[i] + 3
p = [1] #i番目にはi番目に作られるハンバーガーのパティの枚数　: p[i+1] = 2 * p[i] + 1
for i in range(N):
    a.append(2*a[i]+3)
    p.append(2*p[i]+1)
def function(N,X):
    if N <= 0 :
        return 0 if X<= 0 else 1
    elif X <= a[N-1] + 1 :
        ret = function(N-1,X-1)
        return ret
    else:
        ret  = 1 + p[N-1]
        ret +=  function(N-1,X-a[N-1]-2)
        return ret
print(function(N,X))
