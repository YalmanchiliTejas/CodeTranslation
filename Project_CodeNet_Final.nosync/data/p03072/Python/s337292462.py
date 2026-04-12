N = int(input())
h_list = list(map(int, input().split()))

count = 1
for h1 in range(1, N):
    result = True
    for h2 in range(h1):
        if h_list[h2] > h_list[h1]:
            result = False
    if result:
        count += 1
print(count)
