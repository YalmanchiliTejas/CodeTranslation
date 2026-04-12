n = int(input())
A = sorted(int(input()) for i in range(n))
a = [0]*(n)
b = [0]*(n)
c = 1

for i in range(n-1):
    a[i] += -c
    a[i+1] += c
    b[i] += c
    b[i+1] += -c
    c *= -1
a.sort()
b.sort()
sum1,sum2 = 0,0
for i in range(n):
    sum1 += a[i] *A[i]
    sum2 += b[i] * A[i]
print(max(sum1,sum2))
