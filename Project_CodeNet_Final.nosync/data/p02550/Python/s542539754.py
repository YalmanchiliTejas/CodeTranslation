N, X, M = map(int, input().split())

a = X
S = [0, a]
lasts = [None] * (10 ** 5)
for i in range(1, N):
    a = (a * a) % M
    if a == 0:
        break
    if lasts[a] is not None:
        LA = lasts[a]
        T = i - LA
        print(S[-1] + (S[-1]-S[-T-1])*((N-i)//T) + S[-T-1+(N-i)%T] - S[-T-1])
        exit()
    S.append(S[-1] + a)
    lasts[a] = i

print(S[-1])
