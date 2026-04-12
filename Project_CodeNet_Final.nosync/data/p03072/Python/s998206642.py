N = int(input())
H = list(map(int,input().split()))

H.reverse()

count = 0
for i in range(N):
    count_tmp = 0
    for j in range(i+1,N):
        if H[i] < H[j]:
            count_tmp += 1
            break
    if count_tmp == 0:
        count += 1

print(count)