n = int(input())

if n < 15:
    print(n*800)
else:
    print(n*800-(n//15)*200)