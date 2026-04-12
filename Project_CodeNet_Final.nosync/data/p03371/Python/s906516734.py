def solve(a, b, c, x, y):
    flag = None
    if x < y:
        flag = True
    else:
        flag = False
    if c < (a / 2) and c < (b / 2):
        return c * max(x, y) * 2
    c_many = min(x, y)
    c_total = c * c_many * 2
    return min([
        (y - c_many) * b + c_total if flag else (x - c_many) * a + c_total, 
        a * x + b * y,
        max(x, y) * 2 * c,
    ])
   
if __name__ == '__main__':
    a, b, c, x, y = map(lambda x: int(x), input().split())

    print(solve(a, b, c, x, y))
