h,w = map(int,input().split())
point = 0
for _ in range(h):
    s = input()
    point += s.count("#")

if point == (h+w-1):
    print("Possible")
else:
    print("Impossible")