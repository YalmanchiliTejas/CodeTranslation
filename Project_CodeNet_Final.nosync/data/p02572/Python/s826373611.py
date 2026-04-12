N = int(input())
A = list(map(int, input().split()))

mem = []
h = 0
for i in range(N-1, -1, -1):
    h += A[i]
    mem.append(h)

tmp = 0
for i in range(N-1):
    tmp += A[i]*mem[-(i+1+1)]
print(tmp % (10**9+7))
