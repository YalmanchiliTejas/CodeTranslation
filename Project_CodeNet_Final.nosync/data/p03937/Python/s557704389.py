H,W = (int(i) for i in input().split())

sharps = 0
for i in range(H):
    a = input()
    sharps += a.count("#")

if sharps == (H+W-1):
    print("Possible")
else:
    print("Impossible")