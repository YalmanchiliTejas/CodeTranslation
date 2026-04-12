N = int(input())
H = list(input().split())
test = 0
count = 0
for i in range(N):
    if int(H[i]) >= test:
        count += 1
        test = int(H[i])
    else:
        pass

print(count)
