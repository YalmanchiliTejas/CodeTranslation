N = int(input())
A = sorted([int(_) for _ in input().split()])
#B[i]回の操作をすると全項N-1以下になる
#A[i]-N*B[i]+sum(B)-B[i]<=N-1 が全iで成り立つ
#B[i]=0-(-(a+x+1-N))//(N+1)

def check(x):
    b = [0 - (-(a + x + 1 - N)) // (N + 1) for a in A]
    return sum(b) == x

p = max(0, sum(A) - (N - 1) * N)
while True:
    q = check(p)
    if q:
        break
    p += 1
print(p)
