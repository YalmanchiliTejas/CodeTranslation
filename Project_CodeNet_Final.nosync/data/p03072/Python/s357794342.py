n = input()
h = list(map(int, input().split()))
first = h[0]
for i in range(1, first):
    num = h.count(i)
    for j in range(num):
        h.remove(i)
deled_num = len(h)
x = 0
for j in range(deled_num - 1):
    if h[x] > h[x+1]:
        h.pop(x+1)
    else:
        x += 1
print(len(h))