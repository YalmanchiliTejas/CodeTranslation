

N = int(input())
H = list(map(int, input().split()))

can_view = [0]

for i in range(N):
    if i == 0:
        continue
    
    count = 0
    for j in range(i):
        if H[i] >= H[j]:
            count += 1
    
    if count == i:
        can_view.append(i)
print(len(can_view))