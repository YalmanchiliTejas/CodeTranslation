def gcd_core(a, b):
    if b == 0:
        return a
    else:
        return gcd_core(b, a % b)


def gcd(arr):
    g = gcd_core(arr[0], arr[1])
    for i in range(2, len(arr)):
        g = gcd_core(g, arr[i])
    return g

n = int(input())
arr = list(map(int,input().split()))

ma = 0
ct = 0
for a in arr:
    if ma <= a:
        ma = a
        ct +=1

print(ct)








