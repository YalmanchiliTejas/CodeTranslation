N = int(input())
t = [int(input()) for i in range(N)]
M = max(t)
div = [i for i in range(1, M + 1) if M % i == 0]
di = 0
for i in t:
    for j in div:
        if i <= j:
            di += j - i
            break
print(di)

