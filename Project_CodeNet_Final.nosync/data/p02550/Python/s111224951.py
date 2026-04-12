N, X, M = map(int, input().split())
ans = X
ALL_cal = [False] * M
ALL = []
rou = False
for i in range(N-1):
    X = pow(X, 2, M)
    if ALL_cal[X]:
        num = ALL_cal[X]
        now = i
        rou = True
        break
    ALL.append(X)
    ALL_cal[X] = i
    ans += X
if rou :
    roupe = now - num 
    nokori = N - now - 1
    print(sum(ALL[num:])*(nokori//roupe) + ans + sum(ALL[num:num + nokori%roupe]))
else:
    print(ans)