n = int(input())
print((n * 800) - ((n // 15) * 200) if n >= 15 else n * 800)