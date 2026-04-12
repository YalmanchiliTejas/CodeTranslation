# N A B C X
result = []

while(True):
    str = input().split()
    N = int(str[0])
    A = int(str[1])
    B = int(str[2])
    C = int(str[3])
    X = int(str[4])
    if N == A == B == C == X == 0:
        break

    str = input().split()
    Y = [int(str[i]) for i in range(N)]
    
    i = 0
    while(True):
        if not len(Y) > 0:
            i = i-1
            break
        elif not i <= 10000:
            i = -1
            break

        if X == Y[0]:
            Y.pop(0)
        i += 1
        X = (A * X + B) % C
    
    result.append(i)

for r in result:
    print(r)
