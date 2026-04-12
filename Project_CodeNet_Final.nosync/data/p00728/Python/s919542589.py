while True:
    n = int(input())
    str_list = [int(input()) for _ in range(n)]
    if n==0:
        break
    a = max(str_list)
    b = min(str_list)
    c = sum(str_list)
    tensu = (c-a-b)//(n-2)
    print(tensu)


