N,X = map(int,input().split())

a = [1]
for i in range(N):
    a.append(2*a[-1]+3)

b = [1]
for i in range(N):
    b.append(2*b[-1]+1)

def solve(n,x):
    if n == 0:
        if x == 1:
            return 1
        return 0
    if x == a[n]:
        return b[n]
    if x >= a[n]//2+1:
        return b[n-1] + 1 + solve(n-1,x-a[n]//2-1)
    if x >= 1:
        return solve(n-1,x-1)
    return 0

print(solve(N,X))
