n = int(input())
l = list(map(int,input().split()))
i = 0
j = 0
k = 0
m = 0

for i in range(n):
    for j in range(i):
        if l[j] >= k:
           k = l[j]
    if l[i] >= k:
        m = m + 1

    
print(m)