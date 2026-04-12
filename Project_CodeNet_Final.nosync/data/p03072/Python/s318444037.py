n=int(input())
l = list(map(int, input().split()))
x = 0
for i in range(n):
    a = max(l[0:i+1])
    if l[i] >= a:
        x += 1
print(x)
