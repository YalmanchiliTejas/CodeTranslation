n = int(input())
H = list(map(int, input().split()))

answer = 0
for i in range(n):
    if H[i] == max(H[:i + 1]):
        answer += 1

print(answer)
