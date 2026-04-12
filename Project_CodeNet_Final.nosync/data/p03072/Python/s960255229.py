N = int(input())
H = list(map(int,input().split()))

c = 0

for i in range(N):
    d = 0

    for j in range(i):
        #print(H[i], H[j])
        if H[i] > H[j] or H[i] == H[j]:
            d += 1
    if d == i:
        c += 1
print(c)