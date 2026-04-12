y = int(input())
l = list(map(int, input().split()))
for i in range(len(l)):
    for item in l[:i]:
        if item > l[i]:
            y -= 1
            break

print(y)
