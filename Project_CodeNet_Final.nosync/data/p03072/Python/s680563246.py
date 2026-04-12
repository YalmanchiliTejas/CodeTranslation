n=int(input())
a=list(map(int,input().split()))
h = a[0]
count = 0
for i in range(n):
    if h <= a[i]:
        h = a[i]
        count = count + 1
print(count)