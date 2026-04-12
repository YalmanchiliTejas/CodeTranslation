from queue import Queue
h, w = map(int, input().split())
a = []
for _ in range(h):
    a.append(list(input()))
x = [0, 1]
y = [1, 0]
a[0][0] = 0
q = Queue()
q.put([0, 0])
while (q.qsize() > 0):
    start_y, start_x = q.get()
    for i in range(2):
        xx = start_x + x[i]
        yy = start_y + y[i]
        if (xx >= 0) & (xx < w) & (yy >= 0) & (yy < h):
            if a[yy][xx] == "#":
                a[yy][xx] = a[start_y][start_x] + 1
                q.put([yy, xx])
ans_list = []
for i in range(h):
    ans_list.extend(a[i])
dot_num = ans_list.count(".")
last_num = ans_list[-1]
if last_num != "#":
    if h*w == dot_num + last_num+1:
        ans = "Possible"
    else:
        ans = "Impossible"
else:
    ans = "Impossible"
print(ans)