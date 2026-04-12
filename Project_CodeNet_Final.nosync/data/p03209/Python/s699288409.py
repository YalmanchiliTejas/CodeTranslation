N, X = map(int, input().split())
q = [1]*(N+1)
p = [1]*(N+1)
for i in range(1, N+1):
    q[i] = 2*q[i-1]+3
    p[i] = 2*p[i-1]+1

ans = 0
def search(x, n):
    global ans
    if n==0:
        if x:
            ans += 1
        return
    if x==0:
        return
    
    a = q[n-1] + 2
    b = p[n-1] + 1

    if x > a:
        ans += b
        search(x-a, n-1)
    elif x == a:
        ans += b
    else:
        search(x-1, n-1)

search(X, N)
print(ans)