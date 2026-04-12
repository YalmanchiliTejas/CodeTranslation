n = int(input())
a = [int(num) for num in input().split()]
m = 0
cnt = 0
for i in range(n):
    if m <= a[i]:
        m = a[i]
        cnt += 1
        
print(cnt)