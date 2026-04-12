N, X = map(int, input().split())

def len_L(num):
    l = 0
    for i in range(num+1):
        if i== 0:
            l = 1
        else:
            l = 3 + 2*l
    return l

def count_P(level):
    P = 0
    for i in range(level+1):
        if i == 0:
            P = 1
        else:
            P = 2*P + 1
    return P

count = 0
if N == 1:
    count = min(X-1, 3)
else:
    while True:
        half = int((len_L(N) + 1) / 2)
        if X == 1:
            count += 0
            break
        elif X == len_L(N):
            count += count_P(N)
            break
        elif X == half:
            count += int((count_P(N) + 1) / 2)
            break
        elif X > half:
            count += int((count_P(N) + 1) / 2)
            X = X - half
            N = N - 1
            if N == 1:
                count += min(X-1, 3)
                break
        else:
            X = X - 1
            N = N - 1
            if N == 1:
                count += min(X-1, 3)
                break
print(count)