N, X = map(int, input().split())
q = [1]*(N+1)
p = [1]*(N+1)
for i in range(1, N+1):
    q[i] = 2*q[i-1]+3
    p[i] = 2*p[i-1]+1

ans = 0
s = [(X, N)]
while s:
    x, n = s.pop()
    if n==0:
        if x:
            ans += 1
        continue
    if x==0:
        continue
    
    a = q[n-1] + 2
    b = p[n-1] + 1

    if x > a:
        ans += b
        s.append((x-a, n-1))
    elif x == a:
        ans += b
    else:
        s.append((x-1, n-1))

print(ans)