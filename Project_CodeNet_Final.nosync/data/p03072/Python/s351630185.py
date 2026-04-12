n = int(input())
m = list(map(int, input().split()))
count = 0
high = m[0]
for i in range(n-1):
    if high > m[i+1]:
        count += 1
    else:
        high = m[i+1]
print(n - count)