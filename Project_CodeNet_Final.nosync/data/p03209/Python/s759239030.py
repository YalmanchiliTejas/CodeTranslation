N, X = map(int, input().split())
L2 = [1]
j = 1
for i in range(N+2):
    j *= 2
    L2.append(j)
Y = 0
for i in range(N+1):
    if L2[N+1-i] - 1 == X:
        Y += L2[N-i]
        print(Y)
        break
    elif L2[N+2-i] - 3 == X:
        Y += L2[N+1-i] - 1
        print(Y)
        break
    elif L2[N+1-i] - 1 < X:
        Y += L2[N-i]
        X -= L2[N+1-i] - 1
    else:
        X -= 1
else:
    print(Y)
