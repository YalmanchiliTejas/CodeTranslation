def main():
    N, X = map(int, input().split())
    p, t = 1, 1
    P = [p]
    T = [t]
    for i in range(1, N + 1):
        p = p * 2 + 1
        t = t * 2 + 3
        P.append(p)
        T.append(t)
    r = 0
    i = N
    while i >= 0 and X > 0:
        if X >= T[i]:
            r += P[i]
            X -= T[i]
            if X >= 1:
                r += 1
                X -= 1
        else:
            X -= 1
            i -= 1
    print(r)
main() 
