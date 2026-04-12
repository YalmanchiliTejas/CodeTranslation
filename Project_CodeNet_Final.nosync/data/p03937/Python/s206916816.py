import collections, sys

h, w = map(int, input().split())
count = 0
a = []
a.append("." * (w + 2))
for i in range(h):
    temp = input()
    a.append("." + temp + ".")
    count += temp.count("#")
a.append("." * (w + 2))
if count != h + w - 1:
    print("Impossible")
else:
    queue = collections.deque([[1, 1]])
    d = [[1, 0], [0, 1]]
    while queue:
        test = queue.popleft()
        for i in d:
            x = test[0] + i[0]
            y = test[1] + i[1]
            if (x, y) == (w, h):
                print("Possible")
                sys.exit()
            else:
                if a[y][x] == "#":
                    queue.append([x, y])
    else:
        print("Impossible")