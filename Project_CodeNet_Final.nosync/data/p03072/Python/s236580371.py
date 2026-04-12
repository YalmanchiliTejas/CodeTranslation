N = int(input())
H = list(map(int, input().split()))

lead = H[0]
count = 1

for a in H[1:]:
    if lead <= a:
        lead = a
        count += 1
print(count)
