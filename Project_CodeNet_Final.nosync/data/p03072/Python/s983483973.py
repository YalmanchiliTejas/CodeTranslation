cnt = int(input())
a = list(map(int, input().split()))
total = 0
for i in range(len(a)):
    b = a[0:i+1]
    if max(b) <= a[i]:
        total += 1
print(total)
