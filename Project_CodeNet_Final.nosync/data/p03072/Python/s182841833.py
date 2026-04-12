N = int(input())
H = list(map(int, input().split(' ')))
count = 1
for i in range(1,N):
    result1 = max(H[:i])
    if H[i] >= result1:
        count += 1
print(count)
