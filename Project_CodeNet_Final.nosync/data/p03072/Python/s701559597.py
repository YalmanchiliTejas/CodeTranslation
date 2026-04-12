N = int(input())

H = list(map(int, input().split()))

count = 0
max_h = H[0]
for i in H:
    if i >= max_h:
        count += 1
        max_h = i

print(count)