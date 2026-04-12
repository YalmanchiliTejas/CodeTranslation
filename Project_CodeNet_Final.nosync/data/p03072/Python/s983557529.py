N = int(input())
hill = list(map(int, input().split()))
view = 0
f = False
highest = hill[0]
for i in range(N):
    if hill[i] >= highest:
        f = True
        highest = hill[i]
    else:
        f = False
    if f:
        view += 1
print(view)