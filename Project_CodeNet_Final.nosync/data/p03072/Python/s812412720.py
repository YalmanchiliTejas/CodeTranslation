# B - Great Ocean View
N = int(input())
H = list(map(int, input().split()))
count = 1
tmp = H[0]

for i in range(1,N):
    if tmp > H[i]:
        pass
    else:
        tmp = H[i]
        count += 1

print(count)