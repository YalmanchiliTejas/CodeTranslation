N = int(input())
A = list(map(int, input().split()))

ary = [0]*(N-1)
for i in reversed(range(N-1)):
    if i+1 >= (N-1):
        ary[i] = A[N-1]
    else:
        ary[i] = ary[i+1] + A[i+1]

s = 0
for i in range(N-1):
    s += A[i]*ary[i]

print(s%(10**9+7))