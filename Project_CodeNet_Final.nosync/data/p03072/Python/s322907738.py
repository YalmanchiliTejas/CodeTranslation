n = int(input())
h = list(map(int,input().split()))

max_height = 0
answer = 0

for i in range(n):
    if max_height <= h[i]:
        max_height = h[i]
        answer += 1

print(answer)
