
h,w = map(int,input().split())
g = [input() for _ in range(h)]
num = 0

for i in range(h):
    num += g[i].count("#")

if h + w == num + 1:
    print("Possible")
else:
    print("Impossible")

