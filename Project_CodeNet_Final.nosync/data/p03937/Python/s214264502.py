h, w = list(map(int, input().split()))

temp = 0
for i in range(h):
    temp += input().count('#')
print("Possible" if temp == h+w-1else "Impossible")
