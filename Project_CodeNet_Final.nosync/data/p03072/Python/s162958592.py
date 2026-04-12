N = int(input())
H = list(map(int, (input().split())))
c = 0
nax = 0
for i in range(N):
    nax = max(nax, H[i])
    if H[i] == nax:
        c += 1
print(c)
