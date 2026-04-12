import numpy
h,w = map(int,input().split())
grid = numpy.empty([h,w], str)
white_h = []
white_w = []
for i in range(h):
    grid[i] = list(input())
for i in range(h):
    if "#" not in grid[i]:
        white_h.append(i)
for i in range(w):
    if "#" not in grid[:, i]:
        white_w.append(i)
ans_grid = numpy.empty([h-len(white_h), w-len(white_w)], str)
cnt_h = 0
for i in range(h):
    if i not in white_h:
        cnt_w = 0
        for j in range(w):
            if j not in white_w:
                ans_grid[cnt_h, cnt_w] = grid[i,j]
                cnt_w += 1
        cnt_h += 1
for i in range(len(ans_grid)):
    print("".join(ans_grid[i]))



