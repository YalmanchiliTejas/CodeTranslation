N = int(input())
x = N * 800
y = (N // 15) * 200
print(x - y if N >= 15 else x)