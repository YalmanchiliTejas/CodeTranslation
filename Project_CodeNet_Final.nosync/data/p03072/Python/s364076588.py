N = int(input())
x = list(map(int, input().split()))
c = 0
H = 0
for n in range(N):
    if x[n] >= H:
        c += 1
        H = x[n]
print(c)