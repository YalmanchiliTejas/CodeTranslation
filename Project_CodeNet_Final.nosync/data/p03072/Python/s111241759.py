N = int(input())
H = list(map(int, input().split()))

count = 1
for i in range(N-1,0,-1):
    subcount = 0
    for j in range(1,i+1):
        if H[i] >= H[i-j]:
            subcount += 1
        else:
            break
    if subcount == i:
        count += 1
print(count)