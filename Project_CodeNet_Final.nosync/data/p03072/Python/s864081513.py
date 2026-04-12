N = int(input())
H = list(map(int, input().split()))
Hmax = 0
count = 0
for i in range(N):
    if H[i] >= Hmax:
        Hmax = H[i]
        count = count + 1
print(count)