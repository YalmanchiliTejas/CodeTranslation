n = int(input())
h = list(map(int, input().split()))
h1 = h[0]
val = 0
count = 1
for i in h[1:]:
    if i >= val and i >= h1:
        count += 1
        val = i
    else:
        pass
print(count)