h, w = [int(i) for i in input().split()]
cnt = 0
for i in range(h):
    cnt += input().count("#")

if cnt == h+w-1:
    print("Possible")
else:
    print("Impossible")