N = int(input())
li = list(map(int, input().split()))
mireru = []
highest = 0
for i in li:
    if i >= highest:
        mireru.append(1)
        highest = i
print(sum(mireru))