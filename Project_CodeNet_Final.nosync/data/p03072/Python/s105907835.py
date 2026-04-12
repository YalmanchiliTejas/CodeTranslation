N = int(input())
h = list(map(int,input().split()))
a = 0
c = 0
for i in range(N):
    if h[i] >= a:
        c += 1
        a = h[i]
print(c)