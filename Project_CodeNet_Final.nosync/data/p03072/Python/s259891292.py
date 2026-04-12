N = int(input())
H = list(map(int, input().split()))
while len(H) < N:
    H.append(0)
see = 1
for i in range(1, N):
    tall = True
    for j in range(i):
        if(H[j] > H[i]):
            tall = False
            break
    if tall:
        see += 1
print(see)

