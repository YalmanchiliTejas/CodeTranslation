
N = int(input())
H = list(map(int,input().split()))

n = 0
Hmax = 0

for i in range(N):
    if H[i]>=Hmax:
        n += 1
        Hmax = H[i]

print(n)
