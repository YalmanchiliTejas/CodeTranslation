from collections import Counter

H, W = map(int, input().split())

ans = 0
for i in range(H):
    a = input()
    z = Counter(a)
    ans += z["#"]

if ans == H + W - 1:
    print("Possible")
else:
    print("Impossible")