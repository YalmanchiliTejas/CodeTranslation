N = int(input())
discount = 0
if N > 15:
    discount = N // 15
print(N * 800 - discount * 200)
