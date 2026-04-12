n = int(input())
h = list(map(int, input().split()))
count = 1
for i in range(1,n):
    can = True
    for j in range(i):
        if h[i] < h[i-j-1]:
            can = False
            break
    if can:
        count+=1
    else:
        continue
print(count)