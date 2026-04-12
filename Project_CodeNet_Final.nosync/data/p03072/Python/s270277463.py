N = int(input())
H = list(map(int, input().split()))

def can_see_sea(i):
    hi = H[i]
    for h in H[0:i]:
        if h > hi:
            return False
    return True

count = 0

for i in range(N):
    if can_see_sea(i):
        count += 1

print(count)
