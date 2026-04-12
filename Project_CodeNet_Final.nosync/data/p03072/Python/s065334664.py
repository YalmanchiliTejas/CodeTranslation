N = int(input())
H = list(map(int, input().split()))

result = 1
for i in range(1, N):
    if max(H[0:i + 1]) == H[i]:
        result += 1
    else:
        pass
print(result)