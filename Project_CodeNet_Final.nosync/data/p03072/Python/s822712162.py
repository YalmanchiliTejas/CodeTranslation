a = int(input())
h = list(map(int,input().split()))
c = 0
max_h = 0
for i in range(a):
    if h[i] >= max_h :
        max_h = h[i]
        c += 1

print(c)