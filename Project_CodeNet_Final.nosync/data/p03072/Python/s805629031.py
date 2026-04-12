N = int(input())
H = list(map(int, input().split()))
m = 0
c = 0
for i in range(N):
    if m <= H[i]:
        c += 1
        m = H[i]
print(c)
