n = int(input())
h = list(map(int,input().split()))
sh = []
max_h = 0
for i in range(0,n):
    max_h = max(h[i],max_h)
    sh.append(max_h)

count = 0
for i in range(0,n):
    if h[i] >= sh[i]:
        count += 1
print(count)