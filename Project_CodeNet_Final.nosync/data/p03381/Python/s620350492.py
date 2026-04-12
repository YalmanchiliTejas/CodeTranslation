input()
xs = list(map(int, input().split()))
sortx = sorted(xs)
l = len(xs)
t = (l+1)//2 - 1
medv = sortx[t]
if l%2 == 0:
    v1 = medv
    v2 = sortx[t+1]
    for x in xs:
        if x <= medv:
            print(v2)
        else:
            print(v1)
else:
    v1 = sortx[t-1]
    v2 = medv
    for x in xs:
        if x < medv:
            print(v2)
        else:
            print(v1)
