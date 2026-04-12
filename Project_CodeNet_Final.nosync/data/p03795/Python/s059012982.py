n = int(input())
value = 800
result = n * value
if n >= 15:
    result = result - (int(n // 15) * 200)

print(result)