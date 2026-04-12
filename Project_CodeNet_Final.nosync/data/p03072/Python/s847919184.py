N = int(input())
H = list(map(int,input().split()))

hantei = 1

for i in range(1,N):
    for j in range(0,i):
        if H[j] > H[i]:
            break
        if j == i-1:
            hantei = hantei + 1
print(hantei)