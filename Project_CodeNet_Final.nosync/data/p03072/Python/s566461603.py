N = int(input())
H = list(map(int, input().split()))

h = 0
num = 0
for i in H:
    if h <= i:
        num += 1
        h = i
print(num)
