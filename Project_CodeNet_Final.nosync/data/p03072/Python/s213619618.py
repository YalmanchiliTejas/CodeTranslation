n = int(input())
h = [int(e) for e in input().split(" ")]
count = 1
for i in range(n-1,0,-1):
    if max(h[0:i]) <= h[i]:
        count += 1
print(count)