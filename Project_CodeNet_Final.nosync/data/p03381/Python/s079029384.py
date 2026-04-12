n = int(input())
*x, = map(int, input().split())
y = sorted(x)
p, q = y[n//2-1:n//2+1]
ans = []
for i in range(n):
    if x[i] < q:
        ans.append(q)
    else:
        ans.append(p)
print(*ans, sep='\n')

