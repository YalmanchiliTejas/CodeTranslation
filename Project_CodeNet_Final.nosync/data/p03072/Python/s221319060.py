N = int(input())
Hs = list(map(int, input().split()))

c = 1
for i in range(1, N):
    for j in range(0, i):
        if Hs[j] > Hs[i]:
            break
    else:
        c += 1
print(c)