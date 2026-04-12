n = int(input())

if n >= 15:
    x = n * 800
    y =( n // 15 ) * 200
    answer = x - y
    print(answer)
else:
    answer = n * 800
    print(answer)