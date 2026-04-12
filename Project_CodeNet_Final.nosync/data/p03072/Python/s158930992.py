n = int(input())
h_a = [int(i) for i in input().split()]
count = 0

for i, h in enumerate(h_a):
    if h >= max(h_a[0:i+1]):
        count += 1

print(count)
