a = int(input())
h = list(map(int, input().split()))
count = 1


for i in range(1, len(h)):
    for m in range(0,i):
        if h[i] < h[m]:
            break
        if m == i - 1:
            count += 1

print(count)
