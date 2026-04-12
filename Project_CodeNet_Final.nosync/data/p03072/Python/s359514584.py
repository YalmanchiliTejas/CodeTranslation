N = int(input())
H = list(map(int, input().split()))

result = 0
height = 0
for h in H:
    if h >= height:
        result += 1
        height = h

print(result)