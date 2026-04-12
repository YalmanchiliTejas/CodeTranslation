n = int(input())
h = list(map(int,input().split()))
c = 0
for i in range(n):
    if max(h[0:i+1])<=h[i]:
        c = c+1
print(c)