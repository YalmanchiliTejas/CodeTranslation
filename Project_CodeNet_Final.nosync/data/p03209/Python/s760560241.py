# -*- coding: utf-8 -*-
def inpl(): return list(map(int, input().split()))


N, X = inpl()

def main(N, X):
    B = [0]
    P = [1]
    T = [1]
    
    for i in range(50):
        b, p, t = B[-1], P[-1], T[-1]
        B.append(2*b + 2)
        P.append(2*p + 1)
        T.append(2*t + 3)
    
    ans = 0
    for n in range(N, 0, -1):
        if X <= T[n-1]:
            X -= 1
        elif X <= T[n-1] + 2:
            ans += P[n-1] + (X == T[n-1]+2)
            break
        elif X < 2*T[n-1] + 2:
            ans += P[n-1] + 1
            X -= (T[n-1] + 2)
        else:
            ans += 2*P[n-1] + 1
            break
    return ans

print(main(N, X))