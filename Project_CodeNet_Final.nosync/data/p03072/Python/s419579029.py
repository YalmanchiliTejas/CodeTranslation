N = int(input())
H = [int(i) for i in input().split()]

s = [1 if max(H[:i]) <= H[i] else 0 for i in range(1, N)]
print(sum(s) + 1)
