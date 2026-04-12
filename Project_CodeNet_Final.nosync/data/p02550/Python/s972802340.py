n, x, m = map(int, input().split())
A = []
al = [-1]*(m+1)
cnt = 0
for i in range(n):
    if al[x%m] >= 0:
        break
    al[x%m] = cnt
    A.append(x)
    cnt += 1   
    x = x**2 % m

if n <= al[x]:
    print(sum(A[:al[x]]))
    exit()

lena = len(A)
loop = A[al[x]:]
lenl = cnt-al[x]
n -= al[x]
cnt = n//lenl
print(sum(A[:al[x]]) + sum(loop)*cnt + sum(loop[:n%lenl]))