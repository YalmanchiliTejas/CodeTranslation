N = int(input())
M = N//2
x = list(map(int, input().split()))
y = sorted(x)

thre = y[M]

ans_b = y[M]
ans_s = y[M-1]

for x_ in x:
    if x_ >= thre:
        print(ans_s)
    else:
        print(ans_b)