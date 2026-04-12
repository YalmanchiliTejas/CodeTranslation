n = int(input())
h = list(map(int, input().split()))

count = 1

for i in range(1, len(h)):
    if h[i] == max(h[:i+1]):
        count += 1

print(count)
