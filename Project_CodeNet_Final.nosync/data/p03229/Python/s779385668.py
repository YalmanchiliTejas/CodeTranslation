N = int(input())
A = [int(input()) for i in range(N)]

A.sort()

x1 = x2 = A[0]

i = 1
j = len(A) - 1

result = 0

while i <= j:
    a1 = A[i]
    a2 = A[j]
    d1 = abs(x1 - a1)
    d2 = abs(x1 - a2)
    d3 = abs(x2 - a1)
    d4 = abs(x2 - a2)
    ds = [d1, d2, d3, d4]
    dmax = max(ds)
    if dmax == d1:
        i += 1
        x1 = a1
        result += d1
    elif dmax == d2:
        j -= 1
        x1 = a2
        result += d2
    elif dmax == d3:
        i += 1
        x2 = a1
        result += d3
    else:
        j -= 1
        x2 = a2
        result += d4

print(result)
