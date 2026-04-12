N = int(input())
HN = list(map(int, input().split()))
count = 1
for i in range(N-1):
    if HN[i+1] >= max(HN[0:i+1]):
        count += 1
print(count)