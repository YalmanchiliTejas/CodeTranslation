N = int(input())
H = list(map(int, input().split()))
sum = 0
for i in range(N):
    h = [H[j] for j in range(i+1)]
    if i == 0:
        sum += 1
        continue
    if H[i] == max(h):
        sum += 1
print(sum)