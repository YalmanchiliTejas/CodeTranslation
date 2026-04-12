N, X = map(int, input().split())

num = [1]
pati = [1]
for i in range(1, N+1):
    num.append(num[i-1]*2 + 3)
    pati.append(pati[i-1]*2 + 1)

def f(N, X): ## レベルＮバーガーのＸ層目までのパティの数
    if N==0:
        return 1
    
    if X==1:
        return 0
    elif 2<=X<=num[N-1]+1:
        return f(N-1, X-1)
    elif X==num[N-1]+2:
        return pati[N-1]+1
    elif num[N-1]+3<=X<=2*num[N-1]+2:
        return pati[N-1]+1 + f(N-1, X-num[N-1]-2)
    else:
        return pati[N]
print(f(N, X))