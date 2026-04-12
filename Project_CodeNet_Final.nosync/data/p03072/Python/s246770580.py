N = int(input())
H = [int(h) for h in input().split()]
c = 0
for i in range(N):
    if H[i] == max(H[:i + 1]):
        c += 1
print(c)