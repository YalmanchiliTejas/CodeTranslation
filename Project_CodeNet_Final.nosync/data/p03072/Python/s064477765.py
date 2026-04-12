N= int(input())
H = [int(i) for i in input().split()]
check = 1
count = 0
for i in range(N):
    check = max(check, H[i])
    if check <= H[i]:
        count += 1
print(count)