H, W = map(int, input().split())
num = 0
for i in range(H):
    s = input()
    num += s.count("#")

if num == H + W - 1:
    print("Possible")
else:
    print("Impossible")
