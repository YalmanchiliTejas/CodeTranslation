h,w = map(int,input().split())
sums = 0
for i in range(h):
    sums += str(input()).count("#")
if sums == h+w-1:
    print("Possible")
else:
    print("Impossible")