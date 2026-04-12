n = int(input())
a = list(map(int, input().split()))

count = 0

for i in range(1, len(a)):
    
    current = a[i]
    
    while i > 0:
        if current < a[i-1]:
            count += 1
            break
        i -= 1
        
print(n - count)