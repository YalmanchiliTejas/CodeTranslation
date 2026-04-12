N, X = map(int, input().split())

Num = [1] 
for i in range(N):
    Num.append(3 + 2*Num[-1])

def B(L, X): #レベルLのバーガーの下からX層にあるパティの数
    if L == 0: return 1
    elif X == 1: return 0
    else:
        if X <= 1 + Num[L-1]:
            return B(L-1, X-1)
        elif X == 2 + Num[L-1]:
            return B(L-1, Num[L-1]) + 1
        elif X <= 2 + 2*Num[L-1]:
            return B(L-1, Num[L-1]) + 1 + B(L-1, X - 2 - Num[L-1])
        elif X == 3 + 2 * Num[L-1]:
            return 2*B(L-1, Num[L-1]) + 1

print(B(N, X))
