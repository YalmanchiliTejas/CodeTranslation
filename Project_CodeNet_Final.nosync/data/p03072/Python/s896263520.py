from sys import stdin

n = stdin.readline().rstrip().split()
h = [int(x) for x in stdin.readline().rstrip().split()]

sum = 0

for k in range(len(h)):
    if k == 0:
        sum += 1
        continue

    for l in range(k):
        if h[k] < h[l]:
            break
    else:
        sum += 1

print(sum)
