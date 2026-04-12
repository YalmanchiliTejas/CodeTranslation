n = int(input())
h = list(map(int, input().split()))
c = 1
for i in range(1, n):
    b = [x for x in h[:i] if x > h[i]]
    if len(b) == 0:
        c = c + 1
print(c)
