n = int(input())
print([n * 800, (n * 800) - ((n // 15) * 200)][n >= 15])