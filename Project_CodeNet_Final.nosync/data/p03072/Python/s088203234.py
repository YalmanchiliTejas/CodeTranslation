N = int(input())
H = [int(line) for line in input().split()]

ans = []
for i in range(1,N):
    count = 0
    for j in range(i):
        if H[i] >= H[j]:
            count += 1
    if count == i:
        ans.append(i)
print(len(ans)+1)