
N = int(input())
H = list(map(int, input().split()))

ans = 1
for i, val in enumerate(H):
    if i == 0:
        continue

    if not sum(x > val for x in H[:i]):
        ans += 1

print(ans)
