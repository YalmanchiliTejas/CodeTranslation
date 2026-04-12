while True:
    n = int(input())
    if n==0: break
    a = []
    for _ in range(n):
        a.append(int(input()))
    a.sort()
    a.pop()
    a.pop(0)
    print(sum(a)//(n-2))