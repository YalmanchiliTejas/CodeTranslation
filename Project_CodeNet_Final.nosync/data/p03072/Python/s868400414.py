N = int(input())
H = [int(h) for h in input().split()]
count = 0
for i in range(N):
    can_see = True
    for j in range(i):
        if H[j] > H[i]:
            can_see = False
            break
    if can_see:
        count += 1

print(count)