from bisect import bisect_right

n = int(input())
a = [int(input()) for _ in range(n)]

b = []

ans = 1
b.append(a[n-1])

for i in range(n-2, -1, -1):
    if a[i] >= b[-1]:
        b.append(a[i])
    else:
        x = bisect_right(b,a[i])
        b[x] = a[i]
        x -= 1
        while x >= 0:
            if b[x] > b[x+1]:
                b[x],b[x+1] = b[x+1],b[x]
                x -= 1
            else:
                break
    #print(b)

print(len(b))

