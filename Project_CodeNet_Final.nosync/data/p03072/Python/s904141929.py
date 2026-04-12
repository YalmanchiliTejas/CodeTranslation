m = int(input())
a = list(map(int,input().split()))

n = 1
ma = a[0]
for i in range(m-1):
    if ma <= a[i+1]:
        n += 1
        ma = a[i+1]

print(n)