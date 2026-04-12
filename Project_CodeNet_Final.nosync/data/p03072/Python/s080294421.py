
n = int(input())
h = list(map(int,input().split()))
count = 1

lead = h[0]
for a in h[1:]:
    if lead <= a:
        lead = a
        count += 1
print(count)


