N = int(input())
H = list(map(int, input().split()))
count = N

for i in range(N) :
    for j in range(i) :
        if H[i] < H[j]:
            count = count - 1
            break

print (count)