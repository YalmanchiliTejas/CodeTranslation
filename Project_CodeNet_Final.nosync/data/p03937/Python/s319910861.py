h, w = map(int, input().split())
cnt = 0
for i in range(h):
    cnt += list(input()).count("#")

if cnt == h+w-1:
    print("Possible")
else:
    print("Impossible")