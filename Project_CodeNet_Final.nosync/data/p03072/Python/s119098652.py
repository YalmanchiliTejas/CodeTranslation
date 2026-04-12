n = int(input())
h = list(map(int, input().split()))
high = -float("inf")
x = 0
for i in range(n):
     if h[i] >= high:
          high = h[i]
          x += 1
print(x)