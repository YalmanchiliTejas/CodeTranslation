N = int(input())
A = list(map(int,input().split()))

ans = 0
s = 0

def mod(x):
    return int(x % int(1e+9 + 7))

for i in reversed(range(N-1)):
    s += A[i+1]
    s = mod(s)
    ans += A[i] * s

    ans = mod(ans) 

print(int(ans))