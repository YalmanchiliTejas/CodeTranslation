n = int(input())
h = list(map(int, input().split()))
count = 0
for i in range(n):
    view = h[0:i+1]
    if view[-1] == max(view):
        count += 1
print(count)