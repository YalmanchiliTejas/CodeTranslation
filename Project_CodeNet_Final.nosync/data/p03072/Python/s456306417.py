N = int(input())
li = list(map(int, input().split()))
ct = 1
for i in range(1, N):
    if max(li[0:i]) <= li[i]:
        ct += 1
print(ct)