N, X = map(int, input().split())
a, p = [1], [1]
for i in range(N):
    a.append(a[i]*2+3)
    p.append(p[i]*2+1)
    
def p_num(n,x):
    if n==0:
        if x<=0:
            return 0
        else:
            return 1
    elif x<= 1+a[n-1]: #このレベルのバーガーで終了するとき
        return p_num(n-1,x-1)
    else:
        return p[n-1] + 1 + p_num(n-1,x-2-a[n-1])
print(p_num(N,X))