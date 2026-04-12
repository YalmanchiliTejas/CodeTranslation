N = int(input())

H = list(map(int, input().split()))

count = 0

for i in range(N):
    cansee = True
    for j in range(i):
        if H[j] > H[i]:
            cansee = False
    
    if cansee:
        count += 1

print(count)