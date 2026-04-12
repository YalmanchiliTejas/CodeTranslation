H, W = map(int, input().split())

s = 0
for i in range(H):
    A = list(input())
    s += A.count("#")

if s == H + W - 1:
    print("Possible")
else:
    print("Impossible")
