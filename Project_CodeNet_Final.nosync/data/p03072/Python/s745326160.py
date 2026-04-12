n = int(input())
h = [int(i) for i in input().split()]
a = 0
for i in range(len(h)):
    if i == 0:
        a += 1
    else:
        if h[i] >= max(h[0:i]):
            a += 1
print(a)