n = int(input())
h = [int(a) for a in input().split()]

result = 0
for i in range(n):
    if all([h[j] <= h[i] for j in range(i)]):
        result += 1

print(result)
