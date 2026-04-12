H, W = map(int, input().split())
a = []
for _ in range(H):
    t = list(input())
    if t.count('.') != W:
        a.append(t)
    # a.append(list(input()))
# x_white = '.' * W
# i, j = 0, 0
# while True:
#     if a[i] == x_white:
#         a.remove(x_white)
#         j += 1
#     else:
#         i += 1
#     if i == H - j:
#         break
# print(a)
for i in range(W):
    y_white = True
    for j in range(len(a)):
        if a[j][i] == '#':
            y_white = False
    if y_white:
        for j in range(len(a)):
            a[j][i] = ''

for i in range(len(a)):
    answer = ''
    for j in a[i]:
        answer += j
    print(answer)
