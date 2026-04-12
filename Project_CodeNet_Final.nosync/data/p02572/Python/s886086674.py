n = int(input())
ai = list(map(int, input().split()))

square_sum_ai = sum(ai) ** 2
sum_ai_square = sum(map(lambda x: x ** 2, ai))

print(((square_sum_ai - sum_ai_square) // 2) % (10 ** 9 + 7))