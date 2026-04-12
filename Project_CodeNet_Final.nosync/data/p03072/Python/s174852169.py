N = int(input())
H = list(map(int, input().split()))
 
count = 0
for i, h in enumerate(H):
    if i == 0:
        count += 1
    elif i == 1:
        count += 1 if  H[1] >= H[0] else 0
    else:
        count += 1 if h >= max(H[:i]) else 0
print(count)