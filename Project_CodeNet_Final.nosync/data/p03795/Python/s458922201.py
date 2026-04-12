n = int(input())
bonus = n % 15
bonus = (n - bonus) / 15
bonus = round(bonus)
print((n * 800) - (bonus * 200))