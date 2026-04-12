N = int(input())
H = list(map(int, input().split()))
count = 0
for i in range(N):
    if H[i] == max(H[:i+1]):
        count += 1
print(count)