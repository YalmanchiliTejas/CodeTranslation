N = int(input())
H = input().split()
H = list(map(int, H))

count = 0

for i in reversed(range(0, N)):
    if(max(H) == H[-1]):
        count += 1
    del H[-1]

print(count)