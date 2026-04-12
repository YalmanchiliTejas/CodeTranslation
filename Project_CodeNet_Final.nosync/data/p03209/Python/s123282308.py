a = list(map(int, input().split()))
c = a[1]
res = 0

b = [[5,3,1]]
for i in range(1,a[0]):
    tmp = [b[i-1][0]*2+3,b[i-1][1]*2+1,i+1]
    b.append(tmp)

for i in range(a[0]-1,-1,-1):
    if b[i][0] * 2 + 1 <= c:
        c = c - b[i][0]*2 - 1
        res = res + b[i][1] * 2 + 1
    elif b[i][0] <= c: 
        c = c - b[i][0]
        res = res + b[i][1]
        if c > 0:
            c = c - 1
            res = res + 1
    c = c - 1

if c > 0:
    res = res + c

print(res)