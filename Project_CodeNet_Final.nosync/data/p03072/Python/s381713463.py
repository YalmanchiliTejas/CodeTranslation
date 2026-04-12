n = int(input())
h = list(map(int, input().split()))
# print(h)
x = 0
for i in range(n):
    if h[i] == max(h[:i+1]):
        x += 1

print(x)
