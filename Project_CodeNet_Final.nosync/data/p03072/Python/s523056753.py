n = int(input())
h = list(map(int, input().split()))

# print(n, h)

count = 0
for i in range(n):
    able_to_see = True
    for j in range(i):
        if h[j] > h[i]:
            able_to_see = False
    if able_to_see:
        count += 1

print(count)
