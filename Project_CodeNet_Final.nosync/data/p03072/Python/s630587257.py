n = int(input())
mountains = list(map(int, input().split()))
memo = 0
result = []
for m in mountains:
    if (m >= memo):
        memo = m
        result.append(m)
print(len(result))