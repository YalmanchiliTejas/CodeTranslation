h, w = list(map(int, input().split()))
#h, w = list(map(int, input().split()))
a = []
for i in range(h):
    x = input()
    if "#" in x:
        a.append(x)

w90 = []
for i in range(w):
    x = ""
    for j in range(len(a)):
        x += a[j][i]

    if "#" in x:    
        w90.append(x)

for i in range(len(w90[0])):
    for j in range(len(w90)):
        print(w90[j][i], end="")
    print()
