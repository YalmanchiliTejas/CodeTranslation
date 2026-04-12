n = int(input())
a = list(map(int, input().split()))
count = 1
for i in range(n-1):    
    if max(a[0:i+1]) <= a[i+1]:
        count += 1
print(count)