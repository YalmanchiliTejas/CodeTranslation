N = int(input())
H = list(map(int, input().split()))
num_can_see = 1
for n in range(N):
    if n == 0:
        continue
    if max(H[:n]) <= H[n]:
        num_can_see += 1
print(num_can_see)