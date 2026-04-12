N = int(input())
H = list(map(int, input().split(' ')))

count = 1
for i in range(1,N):
    if max(H[:i]) <= H[i]:
        count += 1
print(count)