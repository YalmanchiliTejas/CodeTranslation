import copy

h,w = map(int, input().split())
list_a = []
for i in range(0,h):
    list_a.append(list(str(input())))

list_check = copy.deepcopy(list_a)
for i in range(0,h):
    for j in range(0,w):
        list_a[i][j] = "."

i = 0
j = 0
while True:
    if i == h-1 and j == w-1:
        list_a[i][j] = "#"
        break
    if list_check[i][j] == "#":
        list_a[i][j] = "#"
        if i != h-1:
            i += 1
        else:
            j += 1
    else:
        i -= 1
        j += 1
        if j > w-1:
            ans = "Impossible"
            break
        if list_check[i][j] == ".":
            ans = "Impossible"
            break
if list_a == list_check:
    ans = "Possible"
else:
    ans = "Impossible"
print(ans)
