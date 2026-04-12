n = int(input())
x = list(map(int, input().split()))
y = x.copy()
x = sorted(x)
l = x[n//2-1]
r = x[n//2]
for i in y:
    if i <= l:
        print(x[n//2])
    else:
        print(x[n//2-1])
