hoge = ["FizzBuzz" if i % 15 == 0 else("Fizz" if i % 3 == 0 else("Buzz" if i % 5 == 0 else str(i))) for i in range(10001)]

while True:
    m, n = map(int, input().split())
    if m == 0:
        break
    man = list(range(1, m+1))
    game = [input() for _ in range(n)]
    idx = 0
    for i in range(n):
        if game[i] != hoge[i+1]:
            del man[idx]
            if len(man) == 1:
                break
        else:
            idx += 1
        idx %= len(man)
    print(*man)