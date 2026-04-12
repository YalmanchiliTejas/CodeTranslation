n = int(input())
y = list(map(int, input().split()))
x = sorted(y)
print(*[ x[n//2] if i < x[n//2] else x[n//2-1] for i in y ], sep="\n")