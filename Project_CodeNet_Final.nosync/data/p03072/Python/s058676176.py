N = int(input())
H = list(map(int, input().split()))
count = 0

for i in range(1,N+1):
    if max(H[:i]) == H[i-1]:
        count += 1

print(count)