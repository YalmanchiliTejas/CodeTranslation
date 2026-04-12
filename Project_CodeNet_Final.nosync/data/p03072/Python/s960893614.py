a=int(input())
h = list(map(int,input().split()))
c = 1
max_h = h[0]

for i in range(1, len(h)):
    if h[i] >= max_h:
        max_h = h[i]
        c += 1

print(c)