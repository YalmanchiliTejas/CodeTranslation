
N = int(input())
Hs = list(map(int, input().split()))

count = 0
max_mount = -1
for i in range(len(Hs)):
    if max_mount <= Hs[i]:
        count += 1
        max_mount = Hs[i]

print(count)