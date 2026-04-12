A, B, C, X, Y = map(int, input().split())
min1 = 10**18
max1 = max(X, Y)
for i in range(0, max1+1):
    if Y-i<0 and X-i<0:
        cnt = C*2*i
    elif Y-i<0:
        cnt = C*2*i + A*(X-i)
    elif X-i<0:
        cnt = C*2*i + B*(Y-i)
    else:
        cnt = C*2*i + A*(X-i) + B*(Y-i)
    if cnt<min1:
        min1 = cnt
print(min1)